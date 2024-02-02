#include <iostream>


class Renderer;


class AbstractLayer {
public:
    virtual void render(Renderer &renderer) = 0;
};


template<typename Derived>
class RenderedLayer : public AbstractLayer {
public:
    void render(Renderer &renderer) override;
};


class TileLayer : public RenderedLayer<TileLayer> {};

class ObjectLayer : public RenderedLayer<ObjectLayer> {};

/* 
// You could get rid of the (slightly confusing RenderedLayer class, 
// but the RenderedLayer CRTP class saves you from having to write
// the same `render` function out for each derived class:

class TileLayer : public AbstractLayer {
public:
    void render(Renderer &renderer) {
        renderer.render(static_cast<TitleLayer&>(*this));
    }
};

class ObjectLayer : public AbstractLayer {
public:
    void render(Renderer &renderer) {
        renderer.render(static_cast<ObjectLayer&>(*this));
    }
};
*/


class Renderer {
public:
    void render(TileLayer &layer) {
        std::cout << "I'm a TileLayer" << std::endl;
    }

    void render(ObjectLayer &layer) {
        std::cout << "I'm a ObjectLayer" << std::endl;
    }
};


template<typename Derived>
void RenderedLayer<Derived>::render(Renderer &renderer) { 
    renderer.render(static_cast<Derived&>(*this));
}



int main() {
    Renderer renderer;
    AbstractLayer *tile = new TileLayer;
    AbstractLayer *object = new ObjectLayer;
    tile->render(renderer);
    object->render(renderer);
}
