#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//���ǰ���׺���ʽת���ɺ�׺���ʽ���� 
class Transform{
	private:
		char* str;
		int top;
		int size;
	public:
		//���ʽ��ֵ�Ĺ��캯�� 
		Transform(int size){
			this->size = size;
			str = new char[size];
			top = -1;
		}
		
		//ջ�Ƿ�Ϊ�յĺ���
		bool IsEmpty(){
			return top == -1;
		}
		
		//ջ�Ƿ������ĺ���
		bool IsFull(){
			return top == this->size-1;
		}
		
		//��ջ����
		void Push(char ch){
			if(!this->IsFull()){
				this->str[++top] = ch;	
			}
		}
		
		//���ջ��Ԫ�� 
		char Top(){
			return this->str[top];
		}
		
		//��ջ����
		void Pop(){
			this->top--;
		} 
		
		//ջ����������ȼ� 
		int icp(char ch){
			int result = 0;
			if(ch == '#'){
				result = 0;
			}
			if(ch == '('){
				result = 6;
			}
			if(ch == '*'||ch == '/'){
				result = 4;
			}
			if(ch == '+'||ch == '-'){
				result = 2;
			}	
			if(ch == ')'){
				result = 1;
			}
			return result;		
		}
		
		//ջ����������ȼ� 
		int isp(char ch){
			int result = 0;
			if(ch == '#'){
				result = 0;
			}
			if(ch == '('){
				result = 1;
			}
			if(ch == '*'||ch == '/'){
				result = 5;
			}
			if(ch == '+'||ch == '-'){
				result = 3;
			}	
			if(ch == ')'){
				result = 6;
			}
			return result;		
		}
		
		//��׺���ʽתΪ��׺���ʽ����
		string Transform_Median(string median){
			//����׺���ʽ��ջ��׷��"#"��ʾ���� 
			median.append("#"); 
			this->Push('#');
			char* c;
			int cnt = 0;
			char* tmp;
			c = new char[median.length()];
			tmp = new char[median.length()];			//��׺���ʽ���ݴ����� 
			strcpy(c,median.c_str());
			for(int i = 0 ; i < median.length() ; i++){
				//���������ֱ���������׺���ʽ�� 
				if(c[i] >= '0' && c[i] <= '9'){
					tmp[cnt++] = c[i];
				}else{
					//����������֣�����Ҫ��ջ��Ԫ�رȽ���������ȼ� 
					char ch = this->Top();
					//ջ��Ԫ����ջ�ڵ����ȼ���ջ��Ԫ�ص����ȼ���,��ջ��Ԫ����ջ 
					if(this->isp(ch) < this->icp(c[i])){
						this->Push(c[i]); 
					}else if(this->isp(ch) > this->icp(c[i])){
						//ջ��Ԫ����ջ�ڵ����ȼ���ջ��Ԫ�ص����ȼ���
						//��ջ��Ԫ�س�ջ,���������׺���ʽ��,ѭ��������1 
						tmp[cnt++] = ch;
						this->Pop();
						i--;
					}else{
						//ջ��Ԫ����ջ�ڵ����ȼ�����ջ��Ԫ�ص����ȼ�
						//˵���Ѿ����е���#�������ջ���� 
						this->Pop();	
					}
				}
			}
			//������׺���ʽ���ַ��� 
			string after = string(tmp,cnt);
			return after;
		}	
}; 

//���Ǻ�׺���ʽ������ 
class Sum{
	private:
		int* sum;
		int top;
		int size;
	public:
		//���ʽ��ֵ�Ĺ��캯�� 
		Sum(int size){
			this->size = size;
			sum = new int[size];
			top = -1;
		}
		
		//ջ�Ƿ�Ϊ�յĺ���
		bool IsEmpty(){
			return top == -1;
		}
		
		//ջ�Ƿ������ĺ���
		bool IsFull(){
			return top == this->size-1;
		}
		
		//��ջ����
		void Push(int num){
			if(!this->IsFull()){
				this->sum[++top] = num;	
			}
		}
		
		//���ջ��Ԫ�� 
		int Top(){
			return this->sum[top];
		}
		
		//��ջ����
		void Pop(){
			this->top--;
		} 
		
		//��׺���ʽ���
		int Sum_After(string after){
			char* s;
			s = new char[after.length()];
			strcpy(s,after.c_str());
			for(int i = 0 ; i < after.length() ; i++){
				if(s[i] >= '0' && s[i] <= '9'){
					this->Push(s[i]-'0');
				}else{
					int b = this->Top();
					this->Pop();
					int a = this->Top();
					this->Pop();
					int result = 0;
					switch(s[i]){
						case '+': result = a + b ;break;
						case '-': result = a - b ;break;
						case '*': result = a * b ;break;
						case '/': result = a / b ;break;
					};
					this->Push(result);
				}
			}
			return this->Top();
		} 
};


int main()
{
	string median;
	cout<<"��������׺���ʽ��"<<endl;
	cin>>median;
	Transform transform(median.length());
	string after = transform.Transform_Median(median);
	cout<<"��׺���ʽΪ��"<<endl<<after<<endl;
	Sum sum(after.length()); 
	int result = sum.Sum_After(after);
	cout<<"���Ϊ��"<<endl<<result<<endl; 
	
	return 0;
 } 
