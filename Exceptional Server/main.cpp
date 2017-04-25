#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) 
        {
           long long A, B;
           cin >> A >> B;
           
         /*  while(A<1 || A> pow(2,60))
           {
               cin>>A;
           }
           
           while(B<1 || B> pow(2,60))
           {
               cin>>B;
           }*/
            
           try{
          // if(Server::compute(A,B)>0)
               cout<<Server::compute(A,B)<<endl;
           }
           
           catch (std::bad_alloc &e)
           {
              cout<<"Not enough memory"<<endl;
           }
           
            catch( const std::invalid_argument& e ) {
    
              cout<<"Exception: A is negative"<<endl;
            }
           
            catch(const std::exception &ex)
            {
             cout<<"Exception: "<<ex.what()<<endl;
        
            }
           
       /*    catch (const char* msg) {
            cout<<"Exception: "<< msg << endl;
            }
           
            catch (const int number) {
              cout<<"Exception: Divide by Zero"<<endl;
            }
           */
            catch(...)
            {
             cout<<"Other Exception"<<endl;
        
            }
                
        }
	cout << Server::getLoad() << endl;
	return 0;
}