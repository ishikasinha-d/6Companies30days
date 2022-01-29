class Solution {
public:
    double R,X,Y;
    Solution(double radius, double x_center, double y_center) {
       R= radius;
       X= x_center;
       Y= y_center;
    }
    
    double random(){
        return (double)rand() / RAND_MAX; // for generating random points between 0 to 1
    }
    
    vector<double> randPoint() {
        
        /*
        any point in a circle is of the form -> (Rcosθ, Rsinθ)
        For circles having center other than origin, this becomes -> (Xc + Rcosθ, Yc + Rsinθ)
        we'll do rand()/RAND_MAX for generating random points between 0 to 1
        Applying sqrt() to rand()/RAND_MAX to bias the outer end circle points
        */
        vector<double> random_pt(2);
        double len= sqrt(random()) * R;
        double deg= 2 * M_PI * random();
        random_pt[0]= X+ len*cos(deg);
        random_pt[1]= Y+ len*sin(deg);
        
        return random_pt;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */