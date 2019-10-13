#include <QCoreApplication>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define HEIGHT 10
#define LENGTH 10
#define ACCESS 1
#define FORBID 0
#define PATH 2

using namespace std;


class Node
{
public:
    int x, y;
    Node *parent;
    int type;
    bool issearched;
};

bool isreached(vector<Node> &node_list, Node (&node_map)[HEIGHT][LENGTH], int (&end)[2])
{
//    vector<Node>::iterator result = find(node_list.begin(), node_list.end(), node_map[end[1]][end[0]]);

//    if(result == node_list.end())
//        return false;
//    else
//        return true;

    for(int i = 0; i < node_list.size(); i++)
    {
        if(node_list[i].x == end[0] && node_list[i].y == end[1])
            return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i, j;
    int _x, _y;
    int map[HEIGHT][LENGTH] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 0, 0, 0, 0, 1, 1, 0, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
                               1, 0, 0, 1, 0, 1, 1, 1, 0, 1,
                               1, 1, 1, 1, 1, 1, 0, 0, 0, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    Node node_map[HEIGHT][LENGTH];
    Node *node_path;

    int start[2] = {2,2};
    int end[2] = {9,2};

    vector<Node> node_list, node_list_new;//nodes that need to be checked in the next round

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < LENGTH; j++)
        {
            node_map[i][j].x = j;
            node_map[i][j].y = i;
            node_map[i][j].issearched = false;
            if(map[i][j] == 1)
                node_map[i][j].type = ACCESS;
            else
                node_map[i][j].type = FORBID;
        }
    }

    node_list.push_back(node_map[start[1]][start[0]]);
    node_map[start[1]][start[0]].issearched = true;
    node_map[start[1]][start[0]].parent = NULL;

    while(!isreached(node_list, node_map, end))
    {
        for(i = 0; i < node_list.size(); i++)
        {
            _x = node_list[i].x;
            _y = node_list[i].y;

            //up
            if(_y > 0 && node_map[_y - 1][_x].type == ACCESS &&
                    node_map[_y - 1][_x].issearched == false)
            {
                node_map[_y - 1][_x].issearched = true;
                node_map[_y - 1][_x].parent = &node_map[_y][_x];
                node_list_new.push_back(node_map[_y - 1][_x]);
            }


            //down
            if(_y < HEIGHT - 1 && node_map[_y + 1][_x].type == ACCESS &&
                    node_map[_y + 1][_x].issearched == false)
            {
                node_map[_y + 1][_x].issearched = true;
                node_map[_y + 1][_x].parent = &node_map[_y][_x];
                node_list_new.push_back(node_map[_y + 1][_x]);
            }


            //left
            if(_x > 0 && node_map[_y][_x - 1].type == ACCESS &&
                    node_map[_y][_x - 1].issearched == false)
            {
                node_map[_y][_x - 1].issearched = true;
                node_map[_y][_x - 1].parent = &node_map[_y][_x];
                node_list_new.push_back(node_map[_y][_x - 1]);
            }


            //up
            if(_x < LENGTH - 1 && node_map[_y][_x + 1].type == ACCESS &&
                    node_map[_y][_x + 1].issearched == false)
            {
                node_map[_y][_x + 1].issearched = true;
                node_map[_y][_x + 1].parent = &node_map[_y][_x];
                node_list_new.push_back(node_map[_y][_x + 1]);
            }
        }

        node_list = node_list_new;
        node_list_new.clear();
    }

    node_path = &node_map[end[1]][end[0]];
    while(node_path != NULL)
    {
        cout << node_path->x << "," << node_path->y << endl;
        node_map[node_path->y][node_path->x].type = PATH;
        node_path = node_path->parent;
    }

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < LENGTH; j++)
        {
            switch (node_map[i][j].type)
            {
            case ACCESS:
                cout << " ";
                break;
            case FORBID:
                cout << "o";
                break;
            case PATH:
                cout << "*";
                break;
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
