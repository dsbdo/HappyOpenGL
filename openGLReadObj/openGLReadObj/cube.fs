#version 330 core

in vec2 texture_coordinate;
in vec3 Normal;
in vec3 frag_pos;



out vec4 color;

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};


//parallel light
struct DirLight {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};


//点光源
struct PointLight {
	vec3 position;
	//equation
	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};


//spotLight  摄像机灯光
struct SpotLight {
	vec3 position;
	vec3 direction;

	//here is one cos value
	float cut_off;
	//outer outer cut off 
	float outer_cut_off;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;


	float constant;
	float linear;
	float quadratic;
};

uniform vec3 view_pos;
uniform Material material;

uniform DirLight dir_light;
uniform PointLight point_light;
uniform SpotLight spot_light;

vec3 calculateDirLight(DirLight light, vec3 normal, vec3 view_dir);
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 frag_pos, vec3 view_dir);
vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 frag_pos, vec3 view_dir);


void main() {
	//color = vec4(1.0, 1.0, 1.0, 1.0) * texture(material.diffuse, texture_coordinate);
	vec3 normal = normalize(Normal);
	vec3 view_dir = normalize(view_pos - frag_pos);
	
	vec3 result = calculateDirLight(dir_light, normal, view_dir);
	result += calculatePointLight(point_light, normal, frag_pos, view_dir);
	result += calculateSpotLight(spot_light, normal, frag_pos, view_dir);
	color = vec4(result, 1.0);
}

vec3 calculateDirLight(DirLight light, vec3 normal, vec3 view_dir) {
	vec3 light_dir = normalize(-light.direction);
	//ambient light
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, texture_coordinate));
	
	//diffuse light
	float diff = max(dot(normal, light_dir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texture_coordinate));

	//specular light
	vec3 reflect_dir = reflect(-light_dir, normal);
	float spec = pow(max(dot(view_dir, reflect_dir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texture_coordinate));

	return (ambient + diffuse + specular);
//return ambient + diffuse;
}

vec3 calculatePointLight(PointLight light, vec3 normal, vec3 frag_pos, vec3 view_dir) {
    vec3 lightDir = normalize(light.position - frag_pos);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(view_dir, reflectDir), 0.0), material.shininess);
    // 衰减
    float distance    = length(light.position - frag_pos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // 合并结果
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, texture_coordinate));

    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, texture_coordinate));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texture_coordinate));
    //return (ambient + diffuse + specular);
	ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 frag_pos, vec3 view_dir) {
	
	vec3 ambient = light.ambient  * texture(material.diffuse, texture_coordinate).rgb;
	//diffuse
	//vec3 norm = normalize()
	vec3 light_dir = normalize(light.position - frag_pos);
	float diff = max(dot(normal, light_dir), 0.0);
	vec3 diffuse = light.diffuse * diff * texture(material.diffuse, texture_coordinate).rgb;

	//specular 
	vec3 reflect_dir = reflect(-light_dir, normal);
	float spec = pow(max(dot(view_dir, reflect_dir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * texture(material.specular, texture_coordinate).rgb;

	//spotlight
	float theta = dot(light_dir, normalize(-light.direction));
	float epsilon = light.cut_off - light.outer_cut_off;
	float intensity = clamp((theta - light.outer_cut_off)/ epsilon, 0.0, 1.0);
	diffuse *= intensity;
	specular *= intensity;

	//attenuation
	float distance = length(light.position - frag_pos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	vec3 result = ambient + diffuse + specular;
	return result;
}