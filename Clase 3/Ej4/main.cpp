#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> gen_rand_vector() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 15);

    vector<int> vec;

    for (int i=0; i<30; i++){
        vec.push_back(distr(gen));
    }

    return vec;
}

int main()
{
    vector<int> vec = gen_rand_vector();
    unordered_map<int, int> freq;
    int mode = 0;
    int max_freq = 0;

    cout << "Vector: ";
    for (int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }

    for (int i=0; i<vec.size(); i++){
        freq[vec[i]]++;
        if (freq[vec[i]] > max_freq){
            mode = vec[i];
            max_freq = freq[vec[i]];
        }
    }
    cout << "Moda: " << mode << endl;

    return 0;
}
