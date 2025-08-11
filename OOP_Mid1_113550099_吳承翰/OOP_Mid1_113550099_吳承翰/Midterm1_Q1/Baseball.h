#ifndef __BASEBALL_H__
#define __BASEBALL_H__

#define SIZE 9

#include <string>
#include <vector>

using namespace std;

class Baseball {
    private:
        int point;
        vector<string> data;
        vector<int> converted_nums;

        int base[4];
    public:
        Baseball() : point(0) { for (int i = 0; i < 4; ++i) base[i] = 0; }
        void load_data(string file_path);
        void play();
        int get_PA_result(string PA_result);

        void output_result();
};

#endif