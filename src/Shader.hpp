//Vertex Shader
#define	GENERIC_VS_FILENAME			"../src/shader/generic.vs"
#define CIRCLE_VS_FILENAME			"../src/shader/circle.vs"
#define DIFFUSE_PER_VERTEX_VS_FILENAME		"../src/shader/diffuse_per_vertex.vs"
#define ADS_PER_FRAGMENT_VS_FILENAME		"../src/shader/ads_per_fragment.vs"
#define SPHERE_ADS_PER_FRAGMENT_VS_FILENAME	"../src/shader/sphere_ads_per_fragment.vs"
#define APFEL_VS_FILENAME			"../src/shader/apfel.vs"
#define NORMAL_MAPPING_VS_FILENAME		"../src/shader/normal_mapping.vs"

//Fragment Shader
#define	GENERIC_FS_FILENAME			"../src/shader/generic.fs"
#define ADS_PER_FRAGMENT_FS_FILENAME		"../src/shader/ads_per_fragment.fs"
#define ADS_PER_FRAGMENT_PLANE_FS_FILENAME	"../src/shader/ads_per_fragment_plane.fs"
#define NORMAL_MAPPING_FS_FILENAME		"../src/shader/normal_mapping.fs"

typedef GLchar VertexShaderStr;
typedef GLchar FragmentShaderStr;
typedef GLuint VertexShader;
typedef GLuint FragmentShader;
typedef GLuint ShaderProgram;

class Shader
{
protected:
  VertexShaderStr	*generic_vs_str, *circle_vs_str, *ads_per_fragment_vs_str, *sphere_ads_per_fragment_vs_str, *apfel_vs_str, *normal_mapping_vs_str;
  FragmentShaderStr	*generic_fs_str, *ads_per_fragment_fs_str, *ads_per_fragment_plane_fs_str, *normal_mapping_fs_str;
  VertexShader		generic_vs, circle_vs, ads_per_fragment_vs, sphere_ads_per_fragment_vs, apfel_vs, normal_mapping_vs;
  FragmentShader	generic_fs, ads_per_fragment_fs, ads_per_fragment_plane_fs, normal_mapping_fs;
public:
  ShaderProgram		generic_sp, ads_per_fragment_sp, circle_sp, boden_sp, sphere_sp, apfel_sp, normal_mapping_sp;
  
protected:
  int loadShader(GLchar **shaderStr, char *fileName);
  GLuint createShader(GLenum shaderType, const GLchar *shaderStr);
  GLuint createShaderProgram(GLuint vertexShader, GLuint fragmentShader);
public:
  void genShaderPrograms();
};