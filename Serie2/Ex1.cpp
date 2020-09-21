#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect{1,5,6,10,27,29};
    
    for (int i(0); i<vect.size(); i++){
        //cin >> v.at(i);
        cout << vect.at(i) << endl;
    }

    return 0;
}
