#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
 int CharacterCounter(vector<string>&a) {
    int counter = 0;
    for (int i = 0; i < a.size(); i++) {
        counter += a[i].length();
    }
    return counter;
}
int WordCounter(vector<string>&a) {
    int counter = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].length(); j++) {
            if (j > 0&&(a[i][j]==' '||a[i][j]==','||a[i][j]=='.')) {    //�ӵڶ����ַ���ʼ�����ո�򶺺Ż���ʱ�ж�ǰһ���ַ��ǲ��������ַ������ǵĻ��ͼ���һ��������
                if (a[i][j - 1] != ' ' || a[i][j - 1] != ',' || a[i][j - 1] != '.') counter++;
          }
        }
    }
    return counter;
}
int main(int argc,char **argv)
{ 
    string type = argv[1];
    ifstream inputfile(argv[2], ios::in);
    if (!inputfile)return -1;
    string line;
    vector<string>linestring;
    while (getline(inputfile, line))linestring.push_back(line);//һ��һ�еĶ���
    inputfile.close();
    if (type == "-c")cout<<CharacterCounter(linestring);//�����ַ���
    else if (type == "-w")cout<<WordCounter(linestring);//���㵥����
    else cout<<-1;
  
    return 0;

}


