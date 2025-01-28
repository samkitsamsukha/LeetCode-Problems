class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> a;
        int x = 0;
        for(int i = 0; i<n; i++){
            vector<int> temp;
            for(int j = 0; j<n; j++){
                temp.push_back(x);
                x++;
            }
            a.push_back(temp);
        }
        int i = 0;
        int j =  0;
        for(int k = 0; k<commands.size(); k++){
            if(commands[k] == "DOWN"){
                i++;
            }
            else if(commands[k] == "UP"){
                i--;
            }
            else if(commands[k] == "RIGHT"){
                j++;
            }
            else if(commands[k] == "LEFT"){
                j--;
            }
        }
        return a[i][j];
    }
};