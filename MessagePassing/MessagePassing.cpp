#include<bits/stdc++.h>
using namespace std;

// Implement your solution by completing the below function
bool canMessageBePassed(int n, vector<vector<int> > maze) {
        bool possible = true;

    if(maze.size()<=0)
     return true;
    int left=0,down=maze.size();
    int up=0,right=maze[0].size();

    while(left<right && up<down)
    {   
        if(n==0)
            return false;
        
        for(int i=left;i<right;i++)
        {
            if(maze[up][i]!=0)
                n=max(n,maze[up][i]);
            
            else if(n==0)
            return false;

            else 
            n--;

        }
        up++;

        for(int i=up;i<down;i++)
        {
            if(maze[up][i]!=0)
                n=max(n,maze[i][right-1]);
            
            else if(n==0)
            return false;

            else 
            n--;

        }
        right--;

        if(up<down)
        {
          for(int i=right-1;i>=left;i--)
        {
            if(maze[up][i]!=0)
                n=max(n,maze[down-1][i]);
            
            else if(n==0)
            return false;

            else 
            n--;

        }
        
        down--;  
        }
        if(left < right)
        {
            for(int i=down-1;i>=up;i--)
        {
            if(maze[up][i]!=0)
                n=max(n,maze[i][left]);
            
            else if(n==0)
            return false;

            else 
            n--;

        }
        left++;
        }

    }



	return possible;
}

int main() {
        int n , s , m;
        cin >> n >> s >> m;
        assert(1 <= n && n <= 500);
        assert(1 <= s && s <= 1e5);
        assert(1 <= m && m <= 1e5);

        vector<vector<int> > maze(n , vector<int>(n , 0));
        maze[0][0] = s;

        for(int i = 0 ; i < m ; ++i) {
            int x , y , p;
            cin >> x >> y >> p;
            assert(0 <= x && x < n);
            assert(0 <= y && y < n);
            assert(1 <= p && p <= 1e5);
            maze[x][y] = max(maze[x][y] , p);
        }
        bool possible = canMessageBePassed(n, maze);
        cout << (possible ? "Yes\n" : "No\n");
}

