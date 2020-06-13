/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
void clone(UndirectedGraphNode* node,map<UndirectedGraphNode*,UndirectedGraphNode*> &mp)
{
    UndirectedGraphNode* alias = new UndirectedGraphNode(node->label);
    mp[node] = alias;
    for(int i=0;i<node->neighbors.size();i++)
    {
        if(mp.find(node->neighbors[i]) == mp.end())
        clone(node->neighbors[i],mp);
        alias->neighbors.push_back(mp[node->neighbors[i]]);
    }
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
    clone(node,mp);
    return mp[node];
}
