#version 330 core
out vec4 FragColor;
 

//this is record  the object's material include diffuse spec ambient shiness


struct Material2 {
	sampler2D diffuse;
	sampler2D specular;
	//vec3	specular;
	float	shininess;
};


//parallel light
struct DirLight {
	//vec3 position;
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
uniform DirLight dir_light;


//point light
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
#define NR_POINT_LIGHTS 4
uniform PointLight point_lights[NR_POINT_LIGHTS];

//spotlight
struct SpotLight {

};

struct 
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

uniform Material2 material;


uniform Light light;


in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;
vec3 calculateDirLight(DirLight light, vec3 normal, vec3 view_dir);
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 frag_pos, vec3 view_dir);
vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 frag_pos, vec3 view_dir);
void main()
{
	vec3 norm = normalize(Normal);
	vec3 view_dir = normalize(viewPos - FragPos);

	//parallel Light
	vec3 result = calculateDirLight(dir_light, normal, view_dir);

	//point light 
	for(int i = 0; i < NR_POINT_LIGHTS; i++ ) {
		result += calculatePointLight(point_lights[i], normal, FragPos, view_dir);
	}
	//spot light
	result += calculateSpotLight(spotlight, normal, FragPos, view_dir);

	FragColor = vec4(result, 1.0);
}

vec3 calculateDirLight(DirLight light, vec3 normal, vec3 view_dir) {
	vec3 light_dir = normalize(-light.direction);
	//ambient light
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	
	//diffuse light
	vec3 diff = max(dot(normal, light_dir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

	//specular light
	vec3 reflect_dir = reflect(-light_dir, normal);
	float spec = pow(max(dot(view_dir, reflect_dir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

	return (ambient + diffuse + specular);
}

vec3 calculatePointLight(PointLight light, vec3 normal, vec3 frag_pos, vec3 view_dir) {
    vec3 lightDir = normalize(light.position - fragPos);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // 衰减
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // 合并结果
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 frag_pos, vec3 view_dir) {

}