class MyClass
{
	private:
		int num;
	public:
		MyClass(int num)
		{
			this->num=num;
		}
		int getNum()
		{
			return num;
		}
	friend void disp(MyClass&);
};
void disp(MyClass &ref)
{
	cout<<ref.num<<endl;
}
int main()
{
	MyClass m(7);
	disp(m);
}

