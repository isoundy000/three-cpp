
#include "Window.h"
#include "Scene.h"
#include "Camera.h"
#include "Mesh.h"
#include "Camera.h"
#include "PerspectiveCamera.h"
#include "DefaultMaterials.h"
#include "Texture.h"
#include "ImageUtils.h"
#include "CubeGeometry.h"
#include "opengl/GLRenderer.h"
#include "Code.h"

#include <iostream>

using namespace three;

class TriangleDemo : public Window
{
  public:
    TriangleDemo()
      : Window(1024, 768)
    {
      setTitle("Triangle Example");

      scene = new Scene();

      camera = new PerspectiveCamera();
      camera->position.y = 1;
      camera->position.z = 2;
      camera->rotation.x = -0.4;
      scene->add(camera);

      Geometry * geometry = new Geometry();
      geometry->vertices.push_back(Vector3(0, 0.5, 0));
      geometry->vertices.push_back(Vector3(-0.5, 0, 0));
      geometry->vertices.push_back(Vector3(0.5, 0, 0));
      geometry->vertices.push_back(Vector3(0, 0.5, 0));
      geometry->vertices.push_back(Vector3(0.5, 0, 0));
      geometry->vertices.push_back(Vector3(-0.5, 0, 0));
      geometry->faceCount = 2;

      MeshBasicMaterial * material = new MeshBasicMaterial();
      //material->map = ImageUtils::loadTexture("assets/crate.png");
      material->diffuse = Color(1, 0.8, 0.4);
      material->useTextureMap = false;

      mesh = new Mesh(geometry, material);
      //mesh->position.y = 0.4;
      scene->add(mesh);

      renderer = new GLRenderer();
      renderer->setSize(1024, 768);
    }

    void resize(int width, int height)
    {
      renderer->setSize(width, height);
    }

    bool update(double dt)
    {
      mesh->rotation.y += dt * 2.0;
      mesh->matrixWorldNeedsUpdate = true;

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
  TriangleDemo demo;
  demo.run();
  return 0;
}