#include <iostream>
#include <cstdlib>
#include <cmath>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>
#include<string>
#include<cstdlib>
#include<set>
#include<vector>
#include<fstream>
#include<map>
#include <Windows.h>
using namespace std;
using namespace sf;


class Graph
{
public:

    map<pair<string, string>, double> graph;
    vector<string> vec;
    int Nodes;
    int Edges;


    void Visualise();
    vector<string>& getVec() {
        return vec;
    }

    map<pair<string, string>, double >& getGraph() {
        return graph;
    }

    int getEdges() { return Edges; }
    
    double prim(System::String^& output);
    
    void dijkstra(string start, System::String^& output);
    bool findNode(string str) {
        for (int i = 0; i < Nodes; i++) {
            if (vec[i] == str)
                return true;
        }
        return false;
    }

    bool initialise(string fileName) {
        Nodes = 0;
        Edges = 0;
        ifstream read;
        read.open(fileName);
        if (read.fail()) {
            return false;
        }
        string src, dest, w;
        double weight;
        while (read >> src) {
            read >> dest;
            read >> w;
            weight = strtod(w.c_str(), NULL);
            addEdge(src, dest, weight);
            Edges++;
        }

        for (map<pair<string, string>, double>::iterator it = graph.begin(); it != graph.end(); it++) {
            vec.push_back((*it).first.first);
        }
        
        set<string> s(vec.begin(), vec.end());
        vec.assign(s.begin(), s.end());
        Nodes = vec.size();

        return true;
    }


    void addEdge(string start, string end, double wt);

    void display();

    int totalNodes() {
        return Nodes;
    }

    int findDegree(string node) {
        int degree = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (graph[make_pair(node, vec[i])] != 0)
                degree++;
        }
        return degree;
    }

    void showNeig(string node, vector<string>& temp) {
        for (int i = 0; i < vec.size(); i++) {
            if (graph[make_pair(node, vec[i])] != 0)
                temp.push_back(vec[i]);
        }
    }

    void maxminDegree(string& MAX, string& MIN) {
        int max = findDegree(vec[0]), min = max, max_i=0, min_i=0;
        int j; 
        string J;
        for (int i = 1; i < Nodes; i++) {
            J = vec[i];
            j = findDegree(J);
            if (max < j) {
                max = j;
                max_i = i;
            }
            if (min > j) {
                min = j;
                min_i = i;
            }
        }

        MAX = vec[max_i];
        MIN = vec[min_i];
    }

};
void Graph::addEdge(string start, string end, double wt)
{
    graph[make_pair(start, end)] = wt;
    graph[make_pair(end, start)] = wt;
}

void Graph::display() {
    int flag = 0;
    for (int i = 0; i < vec.size(); i++) {
        cout << "\t" << vec[i];
    }
    cout << "\n";

    for (int i = 0; i < vec.size(); i++) {
        bool flag = false;
        for (int j = 0; j < vec.size(); j++) {
            if (!flag)
                cout << vec[i];
            cout << "\t" << graph[make_pair(vec[i], vec[j])];
            flag = true;
        }
        cout << "\n";
    }
}


struct position {
	int x;
	int y;
};

void Graph::Visualise(){

	RenderWindow window;
	window.create(VideoMode(1350, 700), "GRAPH VISULAISATION");
	window.setFramerateLimit(60);

    int h, k;
	vector<position> pos;
    h = window.getSize().x / 2;
    k = window.getSize().y / 2;
    CircleShape circle(2.f);
    circle.setFillColor(Color::Yellow);
	
    int i = 0, radius = 85;
    bool BREAK = false;
    while (i < Nodes) {
        BREAK = false;
        int steps = floor((2 * radius * 3.14) / 20);
        for (int index = 0; index < steps; index++) {
            int x = h + floor(0 + radius * cos(2 * 3.14 * index / steps));
            int y = k + floor(0 + radius * sin(2 * 3.14 * index / steps));
            //draw item at x,y
            circle.setPosition(x, y);
            pos.push_back({ x, y });
            window.draw(circle);
            i++;
            if (i == Nodes)
                break;
            if (x < 0 || x > window.getSize().x )
                BREAK = true;
        }
        radius = radius + 30;
        if (BREAK == true)
            break;
    }
	
    for (int i = 0; i < pos.size(); i++) {
        for (int j = 0; j < pos.size(); j++) {
            if (graph[make_pair(vec[i], vec[j])] != 0) {
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(pos[i].x, pos[i].y), Color::Red),
                    sf::Vertex(sf::Vector2f(pos[j].x, pos[j].y), Color::Red)
                };
                window.draw(line, 2, sf::Lines);
            }
        }
    }
	window.display();
   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
    }
}
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

double Graph::prim(System::String^ &output) {
    double min = 10000;
    string start = vec[0];
    string *parent;
    double* cost;
    parent = new string[Nodes];
    cost = new double[Nodes];

    for (map<pair<string, string>, double>::iterator it = graph.begin(); it != graph.end(); it++) {
        if (min > (*it).second) {
            min = (*it).second;
            start = (*it).first.first;
        }
    }

    output = L"";
    double total = 0;
    string prev = start;
    string* intree = new string[Nodes];
    string n = start;
    int index;
    for (int i = 0; i < Nodes; i++) {
        intree[i] = vec[i];
        if (vec[i] == start) {
            index = i;
        }
        cost[i] = 10000;
    }
    


    while (intree[index] != "") {

        intree[index] = "";

        double w = 1000000; // Infinite
        string min = "";
        int min_next;
        for (int i = 0; i < Nodes; i++) {
            int nextIndex = i;
            string next = vec[i];

            if (intree[nextIndex] != "" && graph[make_pair(vec[index], vec[nextIndex])] > 0) {
                if (w > graph[make_pair(vec[index], vec[nextIndex])]) {
                    w = graph[make_pair(vec[index], vec[nextIndex])];
                    min = vec[nextIndex];
                    min_next = nextIndex;
                }
                if (cost[i] > graph[make_pair(vec[index], vec[i])]) {
                    cost[i] = graph[make_pair(vec[index], vec[i])];
                    parent[i] = vec[index];
                }
            }    
        }

        if (min != "") {
            index = min_next;
        }
    }

    for (int i = 0; i < Nodes; i++) {
        if (vec[i] == start) {
            output += L" ROOT -->  |  ";
            output += gcnew System::String(start.c_str());
            output += L"  | \n\n\n";
            continue;
        }
        else if (cost[i] == 10000)
            continue;
        output += gcnew System::String(parent[i].c_str());
        output += L" --> ";
        output += gcnew System::String(vec[i].c_str());
        output += L" ( ";
        output += System::Convert::ToString(cost[i]);
        output += L" ) \n";
        total += cost[i];
    }
    return total;
}



void Graph::dijkstra(string start, System::String^ &output) {
    bool f = findNode(start);
    if (f == false) {
        output = L"NODE NOT FOUND";
        return;
    }
    output = L"";
    // map<pair<string, string>, double> g = graph;
    string* visited = new string[Nodes];
    string prev = start;
    int index;
    string n = start;
    for (int i = 0; i < Nodes; i++) {
        visited[i] = vec[i];
        if (vec[i] == start) {
            index = i;
        }
    }
    double total = 0;
    double* w = new double[Nodes];
    for (int i = 0; i < Nodes; i++) {
        w[i] = 10000;//infinity

    }
    w[index] = 0;

    while (visited[index] != "") {

        visited[index] = "";

        string min = "";
        int min_next;
        int tempIndex;

        double min_w = 10000;
        double min_v = 10000;
        for (int i = 0; i < Nodes; i++) {
            int nextIndex;
            string next;
            if (graph[make_pair(vec[index], vec[i])] > 0) {
                next = vec[i];
                nextIndex = i;
            }

            if (visited[i] != "" && graph[make_pair(vec[index], vec[i])] > 0 && w[index] + graph[make_pair(vec[index], vec[i])] < w[i]) {
                w[i] = w[index] + graph[make_pair(vec[index], vec[i])];

                if (min_w > w[i]) {
                    min_w = w[i];
                    min = vec[nextIndex];
                    min_next = nextIndex;
                }

            }
            else if(visited[i] != "" && graph[make_pair(vec[index], vec[i])] > 0 && w[index] + graph[make_pair(vec[index], vec[i])] > w[i]) {
                if (min_w > w[i]) {
                    min_w = w[i];
                    min = vec[nextIndex];
                    min_next = nextIndex;
                }
            }
        }


        if (min != "") {
            index = min_next;
        }
      
    }

    for (int i = 0; i < Nodes; i++) {
        if (w[i] == 1000) {
            output += gcnew System::String(vec[i].c_str());
            output += L"  \t\t";
            output += L"INFINITE\n";
        }
        else {
            output += gcnew System::String(vec[i].c_str());
            output += L"  \t\t";
            output += System::Convert::ToString(w[i]);
            output += L"\n";
        }
    }
}