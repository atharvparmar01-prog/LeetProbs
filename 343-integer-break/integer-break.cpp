class Solution {
public:
bool solveLinearSystem(double a1, double b1, double c1, 
                       double a2, double b2, double c2, 
                       int &x, int &y) {

    double det = a1 * b2 - a2 * b1;


    if (abs(det) < 1e-9) {
        return false; 
    }
    x = (c1 * b2 - c2 * b1) / det;
    y = (a1 * c2 - a2 * c1) / det;

    return true;
}

int integerBreak(int n) {
    if(n==2){return 1;}
    if(n==3){return 2;}

    int maxi=-1;

    for(int i=1;i<n/2+1;i++){
        if(n%i ==0){
            int num = pow((n/i),i);
            maxi = max(maxi,num);
        }
        else{
            int x;
            int y;
            int num = n/i;
            solveLinearSystem(1,1,i,num,num+1,n,x,y);
            int res1 = pow(num,x);
            int res2 = pow(num+1,y);
            maxi = max(maxi,res1*res2);
        }
        cout<<maxi<<endl;
    }
    return maxi;
}
};