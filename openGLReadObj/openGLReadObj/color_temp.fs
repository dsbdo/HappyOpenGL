#version 330 core
out vec4 FragColor;
 

//this is record  the object's material include diffuse spec ambient shiness
struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shiness;
};

struct Material2 {
	sampler2D diffuse;
	vec3	specular;
	float	shiness;
};



struct Light {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

uniform Material2 material;
uniform Light light;
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;


void main()
{

	//ambient light
	//float ambient_strength = 0.1;
	//vec3  ambient = material.ambient * light.ambient;
	vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;

	//diffuse light
	//make the vector to be a norm vector
	vec3 norm = normalize(Normal);
	vec3 light_dir = normalize(lightPos - FragPos);
	float diff = max(dot(norm, light_dir), 0.0);
	//vec3 diffuse = light.diffuse *  ( diff * material.diffuse );
	vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;

	//specular light
	vec3 view_dir = normalize(viewPos - FragPos);
	vec3 reflect_dir = reflect(-light_dir, norm);
	float spec = pow(max(dot(view_dir, reflect_dir), 0.0), material.shiness);
	vec3 specular = light.specular * (spec * material.specular);




	vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}




#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    vec3 specular;    
    float shininess;
}; 

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // ambient
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;  
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);  
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 