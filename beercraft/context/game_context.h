#ifndef GMECTX_H
#define GMECTX_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>
#include <beercraft/context/render_context.h>
#include <beercraft/block.h>
#include <beercraft/utils.h>

#include <bits/stdc++.h>
using namespace std;

class GameContext{
    public:
    GameContext(RenderContext* renderContext_){
        renderContext = renderContext_;
        initBlockList();
    }

    Block* getBlockByID(unsigned int id){
        return blockList[id];
    }

    private:
    unordered_map<unsigned int, Block *> blockList;
    RenderContext* renderContext;

    void initBlockList()
    {
        //init blocks from blocks.csv

        string fname = "beercraft/data/blocks.csv";
        //以读入方式打开文件
        ifstream csv_data(fname, ios::in);
        
        if (!csv_data.is_open())
        {
            cout << "Error: opening file fail" << endl;
            exit(1);
        }
        else {
            string line;
        
            vector<string> words; //声明一个字符串向量
            string word;

            // ------------读取数据-----------------
            // 读取标题行
            getline(csv_data, line);
        
            istringstream sin;
            // 按行读取数据
            while (getline(csv_data, line))
            {
                // 清空vector及字符串流,只存当前行的数据
                words.clear();
                sin.clear();
        
                sin.str(line);
                //将字符串流sin中的字符读到字符串数组words中，以逗号为分隔符
                while (getline(sin, word, ','))
                {
                    // cout << word << endl;
                    words.push_back(word); //将每一格中的数据逐个push
                }

                stringstream sst;
                unsigned int id = str2T<unsigned int>(words[0],&sst);
                string label = words[1];
                string modelPath = "objects/blocks/" + words[2] + "/block.obj";
                blockList[id] = new Block(id, label, modelPath);
            }
            csv_data.close();
        }

    }
};

#endif