
#include "Window.h"
#include "Scene.h"
#include "Camera.h"
#include "Mesh.h"
#include "Camera.h"
#include "PerspectiveCamera.h"
#include "MeshBasicMaterial.h"
#include "Texture.h"
#include "ImageUtils.h"
#include "CubeGeometry.h"
#include "GLRenderer.h"

using namespace three;

class CubeDemo : public Window
{
  public:
    CubeDemo()
      : Window(1024, 768)
    {
      setTitle("Cube Example");

      scene = new Scene();

      camera = new PerspectiveCamera(70, 1024.0 / 768.0, 1, 1000);
      camera->position.z = 400;
      scene->add(camera);

      Geometry * geometry = new CubeGeometry(200, 200, 200);
      MeshBasicMaterial * material = new MeshBasicMaterial(ImageUtils::loadTexture("assets/crate.png"));

      mesh = new Mesh(geometry, material);
      scene->add(mesh);

      renderer = new GLRenderer();
      renderer->setSize(1024, 768);
    }

    bool update(double dt)
    {
      mesh->rotation.x += dt * 0.005;
      mesh->rotation.y += dt * 0.01;

      return !isKeyDown(Key::Esc);
    }
    
    void paint()
    {
      renderer->render(scene, camera);
    }

  private:
    Renderer * renderer;
    Scene * scene;
    Camera * camera;
    Mesh * mesh;
};


int main(int argc, char * argv[])
{
  CubeDemo demo;
  demo.run();
  return 0;
}
