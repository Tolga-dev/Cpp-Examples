#include <iostream>
#include <vector>
#include <array>
#define MAX_NODE 5


class Mesh
{

};

class Transform
{
public:
    static Transform origin();

    Transform combine(Transform& other);

    std::array<int,3> GetPosition()
    {
        return pos;
    }
    void SetPosition(std::array<int,3> temp)
    {
           pos =  temp;
    }
private:
    std::array<int,3> pos = {0,0,0};
};

Transform Transform::origin()
{ std::cout << " origin " << std::endl; }


Transform Transform::combine(Transform &other) {
    Transform transform;
    for(size_t i ; i < GetPosition().size(); i++)
        transform.pos[i] = GetPosition()[i] + other.pos[i];
    return transform;
}

class GraphNode
{
public:
    GraphNode graphNode() {};
    GraphNode(Mesh* mesh) : _mesh(mesh), _local(Transform::origin())
    { _dirty = true; std::cout << " Graph Node" << std::endl; }

    void setTransform(Transform transform)
    {
        _local = transform;
        _dirty = true;
    }
    GraphNode* Nodes()
    {
        return *_nodes;
    }
    void render(Transform parent, bool dirty)
    {
        dirty |= _dirty;

        if(dirty)
        {
            std::cout << " dirty! , combine it " << std::endl;
            _local = _local.combine(parent);
            dirty = false;
        }
        if(_mesh != NULL)
        {
            RenderMesh(_mesh, _local);
        }

    }

    void RenderMesh(Mesh* mesh, Transform transform)
    {
        std::cout << " Rendering! " << std::endl;
    }

private:
    Transform _local;
    Mesh* _mesh;
    GraphNode* _nodes[MAX_NODE];
    int _currentChildren;
    bool _dirty;
};


int main()
{
    GraphNode graphNode(Mesh mesh);
    Transform transform;


}
