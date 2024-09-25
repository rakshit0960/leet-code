class Solution {
public:
    int parentfinder(int x,vector<int> &parent)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=parentfinder(parent[x],parent);
    }

    bool unioni(int u,int v,vector<int> &parent,vector<int> &rank)
    {
        int ui=parentfinder(u,parent);
        int vi=parentfinder(v,parent);

        if(ui==vi)
        {
            return false;
        }

        if(rank[ui]<rank[vi])
        {
            parent[ui]=vi;
        }
        else if(rank[vi]<rank[ui])
        {
            parent[vi]=ui;
        }
        else
        {
            parent[vi]=ui;
            rank[ui]++;
        }
        return true;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1,0);

        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }   

        for (const auto& edge : edges)
        {
            int u=edge[0];
            int v=edge[1];

            if(!unioni(u,v,parent,rank))
            {
                return edge;
            }
        } 
        return {};

    }
};