const int N=1e4;
int a[N];
int t[4*N];

void build(int id,int l,int r){
    if(l==r){
        t[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=t[2*id]+t[(2*id)+1];
}

void update(int id,int l,int r,int pos,int val){
    if(pos<l||pos>r)return;
    if(l==r){
        t[id]=val;
        a[l]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    t[id]=t[2*id]+t[id*2+1];
}

int query(int id,int l,int r,int lq,int rq){
    if(lq>r||rq<l)return 0;
    if(l>=lq&&r<=rq)return t[id];
    int mid=(l+r)/2;
    return query(id*2,l,mid,lq,rq)+query(id*2+1,mid+1,r,lq,rq); 
}

void solve() {
  build(1,0,n-1);
}
