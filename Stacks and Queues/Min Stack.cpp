stack<pair<int,int> > st;
MinStack::MinStack() {
    while(!st.empty())
    st.pop();
}

void MinStack::push(int x) {
    if(st.empty())
    st.push(make_pair(x,x));
    else
    st.push(make_pair(x,min(x,st.top().second)));
}

void MinStack::pop() {
    if(!st.empty())
    st.pop();
}

int MinStack::top() {
    if(st.empty())
    return -1;
    return st.top().first;
}

int MinStack::getMin() {
    if(st.empty())
    return -1;
    return st.top().second;
}
