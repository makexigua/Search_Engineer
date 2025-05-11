/*  File Name      dir_scanner.cc
 *  Author         wd_cpp44th_group7th
 *  Gitee          https://gitee.com/magician-007
 *  Created Time   2022-07-29 22:47
 *  Last Modified  2022-07-31 23:16
 */
#include "../include/dir_scanner.h"

#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

namespace search_engine {

DirScanner::DirScanner() {

}
DirScanner::~DirScanner() {

}
void DirScanner::operator()(const string& dirname) {
    traverse(dirname);    
} //函数调用运算符
vector<string>& DirScanner::files() {
    return _files;

}
void DirScanner::traverse(const string& dirname) {
    DIR* dir;
    struct dirent* direntptr; //存储从目录中读取的文件、子目录信息
    dir = opendir(dirname.c_str());
    if(!dir) {
        cout<<"this"<<dirname.c_str()<<"is NULL"<<endl;
        return;
    } 
    while((direntptr = readdir(dir)) != NULL) {
        //把当前目录和上一级目录都去掉，避免死循环
        if(strncmp(direntptr->d_name, ".", 1) !=0 &&strncmp(direntptr->d_name, "..", 2) !=0) {
            _files.push_back(dirname+ "/" + direntptr->d_name);
        } //strncmp:匹配前n个字符串，但是可能会过滤掉.hidden_file
    }
    closedir(dir);
}

} // namespace search_engine
