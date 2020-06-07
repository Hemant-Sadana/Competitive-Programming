struct trie{
    int freq;
    struct trie* child[26];
};
typedef struct trie trie;
trie* gennode()
{
    trie* t = (trie*)malloc(sizeof(trie));
    t->freq = 0;
    for(int i=0;i<26;i++)
    t->child[i] = NULL;
    return t;
}
void insert(string A,trie* root)
{
    int n = A.size(),ind;
    for(int i=0;i<n;i++)
    {
        ind = A[i]-97;
        if(root->child[ind] == NULL)
        {
            root->child[ind] = gennode();
        }
        else
        root->child[ind]->freq++;
        root = root->child[ind];
    }
}
void find(string t,trie* root,vector<string> &ans)
{
    int n = t.size(),i=0,ind;
    string s = "";
    while(1)
    {
        if(i==n)
        return;
        s = s+t[i];
        ind = t[i]-97;
        if(root->child[ind]->freq == 0)
        {
            ans.push_back(s);
            return;
        }
        root = root->child[ind];
        i++;
    }
}
vector<string> Solution::prefix(vector<string> &A) {
    trie *root = gennode();
    int n = A.size();
    vector<string> ans;
    string t;
    for(int i=0;i<n;i++)
    insert(A[i],root);
    for(int i=0;i<n;i++)
    find(A[i],root,ans);
    return ans;
}
