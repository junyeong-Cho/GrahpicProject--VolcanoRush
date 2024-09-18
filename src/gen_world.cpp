#include "gen_world.hpp"

#include "btBulletDynamicsCommon.h"
#include "btBulletCollisionCommon.h"

#include "gl.hpp"
#include "game.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "shaders.hpp"
#include "mesh_gen.hpp"
#include "mesh_instance.hpp"
#include "texture.hpp"
#include "files.hpp"
#include "mesh_loader.hpp"
#include "physics_object.hpp"
#include "obj_loader.hpp"

namespace GenWorld 
{

  void ground() 
  {
    PhysicsObject *gnd =
      MeshLoader::loadPhysicsObject(Files::dataDir()/"ground.mesh");
    gnd->setOrigin({ 0.0f, -50.0f, 0.0f });
    Game::rootNode.addChild(gnd);

    /*
    PhysicsObject *slope =
      MeshLoader::loadPhysicsObject(Files::dataDir()/"slope.mesh");
    slope->setOrigin({ 0.0f, -0.5f, 0.0f });
    Game::rootNode.addChild(slope);
    */


    auto boxes = [](glm::vec3 origin) -> void 
    {
      PhysicsObject *box =
        MeshLoader::loadPhysicsObject(Files::dataDir()/"crate.mesh");
      box->setOrigin(origin);
      Game::rootNode.addChild(box);
    };

    boxes({ 0.0f, -0.7f, 0.0f });

    boxes({ 0.0f, 0.0f, -10.0f });
    boxes({ 6.0f, 3.0f, -14.0f });
    boxes({ 8.0f, 5.0f, -8.0f });
    boxes({ 14.0f, 7.0f, -8.0f });

    boxes({ 19.0f, 7.5f, -4.0f });

    boxes({ 24.0f, 8.0f, 0.0f });
    boxes({ 26.0f, 10.0f, 12.0f });
    boxes({ 20.0f, 12.0f, 20.0f });
    boxes({ 22.0f, 13.0f, 28.0f });
    boxes({ 28.0f, 14.0f, 30.0f });
    boxes({ 32.0f, 15.0f, 28.0f });
    boxes({ 36.0f, 16.0f, 26.0f });
    boxes({ 38.0f, 17.0f, 22.0f });
    boxes({ 40.0f, 18.0f, 16.0f });
    boxes({ 40.0f, 19.0f, 10.0f });
    boxes({ 38.0f, 20.0f, 4.0f });
    boxes({ 36.0f, 21.0f, 2.0f });
    boxes({ 32.0f, 22.0f, 0.0f });
    boxes({ 28.0f, 23.0f, 0.0f });
    boxes({ 24.0f, 24.0f, 1.0f });
    boxes({ 16.0f, 25.0f, 2.0f });
    boxes({ 14.0f, 27.0f, 4.0f });
    boxes({ 12.0f, 28.0f, 10.0f });
    boxes({ 12.0f, 29.0f, 16.0f });
    boxes({ 14.0f, 30.0f, 22.0f });
    boxes({ 16.0f, 31.0f, 26.0f });
    boxes({ 20.0f, 32.0f, 28.0f });
    boxes({ 24.0f, 33.0f, 28.0f });
    boxes({ 28.0f, 34.0f, 26.0f });
    boxes({ 30.0f, 35.0f, 22.0f });
    boxes({ 32.0f, 36.0f, 16.0f });
    boxes({ 32.0f, 37.0f, 10.0f });
    boxes({ 30.0f, 38.0f, 4.0f });
    boxes({ 28.0f, 39.0f, 2.0f });
    boxes({ 24.0f, 40.0f, 0.0f });
    boxes({ 20.0f, 41.0f, 0.0f });
    boxes({ 16.0f, 42.0f, 1.0f });




  


    /*
    Game::rootNode.addChild(MeshLoader::loadPhysicsObject(Files::dataDir()
                                                          /"hall.mesh"));
    Game::rootNode.addChild(MeshLoader::loadPhysicsObject(Files::dataDir()
                                                          /"hall_floor.mesh"));
    */


    PhysicsObject *objThing = ObjLoader::load(Files::dataDir()/"thing.obj");
    objThing->setOrigin({ 22.0f, 3.0f, 0.0f });
    objThing->mesh->shader =
      new Shader(Files::readFile(Files::dataDir()/"shader.vert"),
                 Files::readFile(Files::dataDir()/"shader.frag"));
    objThing->texture = new Texture();
    objThing->texture->load(Files::dataDir()/"crate.jpg", 3, GL_RGB);
    Game::rootNode.addChild(objThing);


    PhysicsObject *objSphere = ObjLoader::load(Files::dataDir()/"sphere.obj");
    objSphere->setOrigin({ -2.0f, 2.0f, -10.0f });
    objSphere->mesh->shader =
      new Shader(Files::readFile(Files::dataDir()/"shader.vert"),
                 Files::readFile(Files::dataDir()/"shader.frag"));
    objSphere->texture = new Texture();
    objSphere->texture->load(Files::dataDir()/"crate.jpg", 3, GL_RGB);
    Game::rootNode.addChild(objSphere);
  }

  void all() 
  {
    ground();
  }

} // namespace GenWorld
