#include <iostream>
class Diagonal{
	private:
		int n;
		int *mPtr;
	public:
		Diagonal(int n){
			this->n=n;
			mPtr=new int[n];
		}
		void set(int element,int row,int column){
			if(row==column){
				mPtr[row]=element;
			}
		}
		int get(int row,int column){
			if(row==column){
				return mPtr[row];
			}
			return 0;
		}
		void display(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(j==i){
						std::cout<<mPtr[i]<<" ";
					}else{
						std::cout<<"0  ";
					}
				}
				std::cout<<std::endl;
			}
		}
		int getN(){
			return n;
		}
		~Diagonal(){
			delete[]mPtr;
		}
};
int main(){
	int size;
	std::cout<<"Enter size: ";
	std::cin>>size;
	Diagonal matrix(size);
	std::cout<<"Enter elements: ";
	for(int i=0;i<matrix.getN();i++){
		for(int j=0;j<matrix.getN();j++){
			if(i==j){
				int element;
				std::cin>>element;
				matrix.set(element,i,j);
			}
		}
	}
	std::cout<<"-----Display-----\n";
	matrix.display();
}