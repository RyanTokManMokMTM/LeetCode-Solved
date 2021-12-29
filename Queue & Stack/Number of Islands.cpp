class Solution {
public:
    bool isOutOfRange(int x,int y,int row,int column,vector<vector<char>>& grid){
        return x >= 0 && x < row && y >= 0 && y < column && grid[x][y] == '1'; //only all condition are true ->t
     }
    
    
    int numIslands(vector<vector<char>>& grid) {
        //using a queue to insead the recursion
        queue<pair<int,int>> island;
        int totalIsland = 0;
        int row = grid.size(); //m
        int column = grid[0].size(); //n
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<column;j++){
                if(grid[i][j] == '1'){
                    //current node is a island
                    totalIsland++;
                    
                    island.push({i,j}); //add current to queue
                    //then need to add the adjacent node to the queue
                    while(!island.empty()){
                        //check adjacent node
                        //get the front elememnt of the queue
                        pair<int,int> current = island.front();
                        island.pop();
                        if(grid[current.first][current.second] == '1'){
                            grid[current.first][current.second] = '0'; //set to 0 => visited
                            //add 4 edges
                            //but we need to check each edge is out of range or not
                            //x,y+1
                            if(isOutOfRange(current.first,current.second+1,row,column,grid)){
                                //add to the queue
                                 island.push({current.first,current.second+1});
                            }
                            
                            //x,y-1
                            if(isOutOfRange(current.first,current.second-1,row,column,grid)){
                                //add to the queue
                                island.push({current.first,current.second-1});
                            }
                            
                            //x+1,y
                            if(isOutOfRange(current.first+1,current.second,row,column,grid)){
                                //add to the queue
                                island.push({current.first+1,current.second});
                            }
                            //x-1,y
                            if(isOutOfRange(current.first-1,current.second,row,column,grid)){
                                //add to the queue
                                island.push({current.first-1,current.second});
                            }
                        }
                    }
                }
            }
        }
        return totalIsland;
    }
};