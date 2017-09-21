#include <iostream>
#include <string>

using namespace std;

class position{
public:
	int row,column;
	position(){
		row=0;column=0;
	}
	position(position &A){
		row=A.row;column=A.column;
	}
};

class matrix{
public:
	char arr[3][3];
	matrix(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++) arr[i][j]='?';
		}
	}

	matrix(matrix &a){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				arr[i][j]=a.arr[i][j];
			}
		}
	}

	void upgrade_matrix(int row_number,int column_number){
		arr[row_number-1][column_number-1]='*';

		return;
	}
	void print_matrix(){
		cout<<endl<<endl;
		for(int j=0;j<3;j++){
			for(int i=0;i<3;i++){
				cout<<"  "<<arr[j][i];
			}
			cout<<endl<<endl;
		}

		return;
	}

};

bool check_rows(matrix &p){
	if((p.arr[0][0]=='*' && p.arr[0][1]=='*' && p.arr[0][2]=='?') || 
		(p.arr[0][0]=='*' && p.arr[0][1]=='?' && p.arr[0][2]=='*') || 
		(p.arr[0][0]=='?' && p.arr[0][1]=='*' && p.arr[0][2]=='*')) return true;

	else if((p.arr[1][0]=='*' && p.arr[1][1]=='*' && p.arr[1][2]=='?') || 
		(p.arr[1][0]=='*' && p.arr[1][1]=='?' && p.arr[1][2]=='*') || 
		(p.arr[1][0]=='?' && p.arr[1][1]=='*' && p.arr[1][2]=='*')) return true;

	else if((p.arr[2][0]=='*' && p.arr[2][1]=='*' && p.arr[2][2]=='?') || 
		(p.arr[2][0]=='*' && p.arr[2][1]=='?' && p.arr[2][2]=='*') || 
		(p.arr[2][0]=='?' && p.arr[2][1]=='*' && p.arr[2][2]=='*')) return true;

	else return false; 
}

bool check_columns(matrix &p){
	if((p.arr[0][0]=='*' && p.arr[1][0]=='*' && p.arr[2][0]=='?') || 
		(p.arr[0][0]=='*' && p.arr[1][0]=='?' && p.arr[2][0]=='*') || 
		(p.arr[0][0]=='?' && p.arr[1][0]=='*' && p.arr[2][0]=='*')) return true;

	else if((p.arr[0][1]=='*' && p.arr[1][1]=='*' && p.arr[2][1]=='?') || 
		(p.arr[0][1]=='*' && p.arr[1][1]=='?' && p.arr[2][1]=='*') || 
		(p.arr[0][1]=='?' && p.arr[1][1]=='*' && p.arr[2][1]=='*')) return true;

	else if((p.arr[0][2]=='*' && p.arr[1][2]=='*' && p.arr[2][2]=='?') || 
		(p.arr[0][2]=='*' && p.arr[1][2]=='?' && p.arr[2][2]=='*') || 
		(p.arr[0][2]=='?' && p.arr[1][2]=='*' && p.arr[2][2]=='*')) return true;

	else return false;	
}

bool check_cross(matrix &p){
	if((p.arr[0][0]=='*' && p.arr[1][1]=='*' && p.arr[2][2]=='?') || 
		(p.arr[0][0]=='*' && p.arr[1][1]=='?' && p.arr[2][2]=='*') || 
		(p.arr[0][0]=='?' && p.arr[1][1]=='*' && p.arr[2][2]=='*')) return true;

	else if((p.arr[0][2]=='*' && p.arr[1][1]=='*' && p.arr[2][0]=='?') || 
		(p.arr[0][2]=='*' && p.arr[1][1]=='?' && p.arr[2][0]=='*') || 
		(p.arr[0][2]=='?' && p.arr[1][1]=='*' && p.arr[2][0]=='*')) return true;

	else return false;
}

bool check_end_condition(matrix &k){

	if(check_rows(k)==true) return true;

	if(check_columns(k)==true) return true;

	if(check_cross(k)==true) return true;

	else return false;

}

position give_position_rows(matrix &p){
	position pos;
	if(p.arr[0][0]=='*' && p.arr[0][1]=='*' && p.arr[0][2]=='?') {pos.row=0;pos.column=2; return pos;} 
	else if(p.arr[0][0]=='*' && p.arr[0][1]=='?' && p.arr[0][2]=='*') {pos.row=0;pos.column=1; return pos;}
	else if(p.arr[0][0]=='?' && p.arr[0][1]=='*' && p.arr[0][2]=='*'){pos.row=0;pos.column=0; return pos;}

	else if(p.arr[1][0]=='*' && p.arr[1][1]=='*' && p.arr[1][2]=='?') {pos.row=1;pos.column=2; return pos;} 
	else if(p.arr[1][0]=='*' && p.arr[1][1]=='?' && p.arr[1][2]=='*') {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[1][0]=='?' && p.arr[1][1]=='*' && p.arr[1][2]=='*') {pos.row=1;pos.column=0; return pos;}

	else if(p.arr[2][0]=='*' && p.arr[2][1]=='*' && p.arr[2][2]=='?') {pos.row=2;pos.column=2; return pos;} 
	else if(p.arr[2][0]=='*' && p.arr[2][1]=='?' && p.arr[2][2]=='*') {pos.row=2;pos.column=1; return pos;}
	else if(p.arr[2][0]=='?' && p.arr[2][1]=='*' && p.arr[2][2]=='*') {pos.row=2;pos.column=0; return pos;}
}

position give_position_columns(matrix &p){
	position pos;
	if(p.arr[0][0]=='*' && p.arr[1][0]=='*' && p.arr[2][0]=='?') {pos.row=2;pos.column=0; return pos;} 
	else if(p.arr[0][0]=='*' && p.arr[1][0]=='?' && p.arr[2][0]=='*') {pos.row=1;pos.column=0; return pos;}
	else if(p.arr[0][0]=='?' && p.arr[1][0]=='*' && p.arr[2][0]=='*'){pos.row=0;pos.column=0; return pos;}

	else if(p.arr[0][1]=='*' && p.arr[1][1]=='*' && p.arr[2][1]=='?') {pos.row=2;pos.column=1; return pos;} 
	else if(p.arr[0][1]=='*' && p.arr[1][1]=='?' && p.arr[2][1]=='*') {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[0][1]=='?' && p.arr[1][1]=='*' && p.arr[2][1]=='*') {pos.row=0;pos.column=1; return pos;}

	else if(p.arr[0][2]=='*' && p.arr[1][2]=='*' && p.arr[2][2]=='?') {pos.row=2;pos.column=2; return pos;} 
	else if(p.arr[0][2]=='*' && p.arr[1][2]=='?' && p.arr[2][2]=='*') {pos.row=1;pos.column=2; return pos;}
	else if(p.arr[0][2]=='?' && p.arr[1][2]=='*' && p.arr[2][2]=='*') {pos.row=0;pos.column=2; return pos;}
}

position give_position_cross(matrix &p){
	position pos;
	if(p.arr[0][0]=='*' && p.arr[1][1]=='*' && p.arr[2][2]=='?') {pos.row=2;pos.column=2; return pos;} 
	else if(p.arr[0][0]=='*' && p.arr[1][1]=='?' && p.arr[2][2]=='*')  {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[0][0]=='?' && p.arr[1][1]=='*' && p.arr[2][2]=='*')  {pos.row=0;pos.column=0; return pos;}

	else if(p.arr[0][2]=='*' && p.arr[1][1]=='*' && p.arr[2][0]=='?') {pos.row=2;pos.column=0; return pos;} 
	else if(p.arr[0][2]=='*' && p.arr[1][1]=='?' && p.arr[2][0]=='*') {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[0][2]=='?' && p.arr[1][1]=='*' && p.arr[2][0]=='*') {pos.row=0;pos.column=2; return pos;}
}

position give_position(matrix &p){
	position pos;
	if(check_rows(p)==true) {pos=give_position_rows(p);return pos;}

	else if(check_columns(p)==true) {pos=give_position_columns(p);return pos;}

	else if(check_cross(p)==true) {pos=give_position_cross(p);return pos;}

}
bool check_rows_to_put_zero(matrix &p){
	if((p.arr[0][0]=='0' && p.arr[0][1]=='0' && p.arr[0][2]=='?') || 
		(p.arr[0][0]=='0' && p.arr[0][1]=='?' && p.arr[0][2]=='0') || 
		(p.arr[0][0]=='?' && p.arr[0][1]=='0' && p.arr[0][2]=='0')) return true;

	else if((p.arr[1][0]=='0' && p.arr[1][1]=='0' && p.arr[1][2]=='?') || 
		(p.arr[1][0]=='0' && p.arr[1][1]=='?' && p.arr[1][2]=='0') || 
		(p.arr[1][0]=='?' && p.arr[1][1]=='0' && p.arr[1][2]=='0')) return true;

	else if((p.arr[2][0]=='0' && p.arr[2][1]=='0' && p.arr[2][2]=='?') || 
		(p.arr[2][0]=='0' && p.arr[2][1]=='?' && p.arr[2][2]=='0') || 
		(p.arr[2][0]=='?' && p.arr[2][1]=='0' && p.arr[2][2]=='0')) return true;

	else return false; 
}

bool check_columns_to_put_zero(matrix &p){
	if((p.arr[0][0]=='0' && p.arr[1][0]=='0' && p.arr[2][0]=='?') || 
		(p.arr[0][0]=='0' && p.arr[1][0]=='?' && p.arr[2][0]=='0') || 
		(p.arr[0][0]=='?' && p.arr[1][0]=='0' && p.arr[2][0]=='0')) return true;

	else if((p.arr[0][1]=='0' && p.arr[1][1]=='0' && p.arr[2][1]=='?') || 
		(p.arr[0][1]=='0' && p.arr[1][1]=='?' && p.arr[2][1]=='0') || 
		(p.arr[0][1]=='?' && p.arr[1][1]=='0' && p.arr[2][1]=='0')) return true;

	else if((p.arr[0][2]=='0' && p.arr[1][2]=='0' && p.arr[2][2]=='?') || 
		(p.arr[0][2]=='0' && p.arr[1][2]=='?' && p.arr[2][2]=='0') || 
		(p.arr[0][2]=='?' && p.arr[1][2]=='0' && p.arr[2][2]=='0')) return true;

	else return false;	
}

bool check_cross_to_put_zero(matrix &p){
	if((p.arr[0][0]=='0' && p.arr[1][1]=='0' && p.arr[2][2]=='?') || 
		(p.arr[0][0]=='0' && p.arr[1][1]=='?' && p.arr[2][2]=='0') || 
		(p.arr[0][0]=='?' && p.arr[1][1]=='0' && p.arr[2][2]=='0')) return true;

	else if((p.arr[0][2]=='0' && p.arr[1][1]=='0' && p.arr[2][0]=='?') || 
		(p.arr[0][2]=='0' && p.arr[1][1]=='?' && p.arr[2][0]=='0') || 
		(p.arr[0][2]=='?' && p.arr[1][1]=='0' && p.arr[2][0]=='0')) return true;

	else return false;
}

position give_position_rows_to_put_zero(matrix &p){
	position pos;
	if(p.arr[0][0]=='0' && p.arr[0][1]=='0' && p.arr[0][2]=='?') {pos.row=0;pos.column=2; return pos;} 
	else if(p.arr[0][0]=='0' && p.arr[0][1]=='?' && p.arr[0][2]=='0') {pos.row=0;pos.column=1; return pos;}
	else if(p.arr[0][0]=='?' && p.arr[0][1]=='0' && p.arr[0][2]=='0'){pos.row=0;pos.column=0; return pos;}

	else if(p.arr[1][0]=='0' && p.arr[1][1]=='0' && p.arr[1][2]=='?') {pos.row=1;pos.column=2; return pos;} 
	else if(p.arr[1][0]=='0' && p.arr[1][1]=='?' && p.arr[1][2]=='0') {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[1][0]=='?' && p.arr[1][1]=='0' && p.arr[1][2]=='0') {pos.row=1;pos.column=0; return pos;}

	else if(p.arr[2][0]=='0' && p.arr[2][1]=='0' && p.arr[2][2]=='?') {pos.row=2;pos.column=2; return pos;} 
	else if(p.arr[2][0]=='0' && p.arr[2][1]=='?' && p.arr[2][2]=='0') {pos.row=2;pos.column=1; return pos;}
	else if(p.arr[2][0]=='?' && p.arr[2][1]=='0' && p.arr[2][2]=='0') {pos.row=2;pos.column=0; return pos;}
}

position give_position_columns_to_put_zero(matrix &p){
	position pos;
	if(p.arr[0][0]=='0' && p.arr[1][0]=='0' && p.arr[2][0]=='?') {pos.row=2;pos.column=0; return pos;} 
	else if(p.arr[0][0]=='0' && p.arr[1][0]=='?' && p.arr[2][0]=='0') {pos.row=1;pos.column=0; return pos;}
	else if(p.arr[0][0]=='?' && p.arr[1][0]=='0' && p.arr[2][0]=='0'){pos.row=0;pos.column=0; return pos;}

	else if(p.arr[0][1]=='0' && p.arr[1][1]=='0' && p.arr[2][1]=='?') {pos.row=2;pos.column=1; return pos;} 
	else if(p.arr[0][1]=='0' && p.arr[1][1]=='?' && p.arr[2][1]=='0') {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[0][1]=='?' && p.arr[1][1]=='0' && p.arr[2][1]=='0') {pos.row=0;pos.column=1; return pos;}

	else if(p.arr[0][2]=='0' && p.arr[1][2]=='0' && p.arr[2][2]=='?') {pos.row=2;pos.column=2; return pos;} 
	else if(p.arr[0][2]=='0' && p.arr[1][2]=='?' && p.arr[2][2]=='0') {pos.row=1;pos.column=2; return pos;}
	else if(p.arr[0][2]=='?' && p.arr[1][2]=='0' && p.arr[2][2]=='0') {pos.row=0;pos.column=2; return pos;}
}

position give_position_cross_to_put_zero(matrix &p){
	position pos;
	if(p.arr[0][0]=='0' && p.arr[1][1]=='0' && p.arr[2][2]=='?') {pos.row=2;pos.column=2; return pos;} 
	else if(p.arr[0][0]=='0' && p.arr[1][1]=='?' && p.arr[2][2]=='0')  {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[0][0]=='?' && p.arr[1][1]=='0' && p.arr[2][2]=='0')  {pos.row=0;pos.column=0; return pos;}

	else if(p.arr[0][2]=='0' && p.arr[1][1]=='0' && p.arr[2][0]=='?') {pos.row=2;pos.column=0; return pos;} 
	else if(p.arr[0][2]=='0' && p.arr[1][1]=='?' && p.arr[2][0]=='0') {pos.row=1;pos.column=1; return pos;}
	else if(p.arr[0][2]=='?' && p.arr[1][1]=='0' && p.arr[2][0]=='0') {pos.row=0;pos.column=2; return pos;}
}

position give_position_to_put_zero(matrix &p){
	position pos;
	if(check_rows_to_put_zero(p)==true) {pos=give_position_rows_to_put_zero(p);return pos;}

	else if(check_columns_to_put_zero(p)==true) {pos=give_position_columns_to_put_zero(p);return pos;}

	else if(check_cross_to_put_zero(p)==true) {pos=give_position_cross_to_put_zero(p);return pos;}
}
void put_zero(matrix &p){
	position pos;
	if(check_rows_to_put_zero(p)) {pos=give_position_rows_to_put_zero(p);p.arr[pos.row][pos.column]='0';return;}
	else if(check_columns_to_put_zero(p)) {pos=give_position_columns_to_put_zero(p);p.arr[pos.row][pos.column]='0';return;} 
	else if(check_cross_to_put_zero(p)) {pos=give_position_cross_to_put_zero(p);p.arr[pos.row][pos.column]='0';return;}
	else for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(p.arr[i][j]=='?') {p.arr[i][j]='0';return;}
			}
		}
}

bool check_win_condition(matrix &p){
	if(check_rows_to_put_zero(p)==true) return true;
	else if(check_columns_to_put_zero(p)==true) return true;
	else if(check_cross_to_put_zero(p)==true) return true;

	else return false;
}

void put_winning_zero(matrix &p){
	position pos;
	if(check_rows_to_put_zero(p)) {pos=give_position_rows_to_put_zero(p);p.arr[pos.row][pos.column]='0';return;}
	else if(check_columns_to_put_zero(p)) {pos=give_position_columns_to_put_zero(p);p.arr[pos.row][pos.column]='0';return;} 
	else if(check_cross_to_put_zero(p)) {pos=give_position_cross_to_put_zero(p);p.arr[pos.row][pos.column]='0';return;}

	else return;
}
bool check_row_for_win(matrix &p){
	if(p.arr[0][0]=='*' && p.arr[0][1]=='*' && p.arr[0][2]=='*') return true;
	else if(p.arr[1][0]=='*' && p.arr[1][1]=='*' && p.arr[1][2]=='*') return true;
	else if(p.arr[2][0]=='*' && p.arr[2][1]=='*' && p.arr[2][2]=='*') return true;
	else return false;
}

bool check_column_for_win(matrix &p){
	if(p.arr[0][0]=='*' && p.arr[1][0]=='*' && p.arr[2][0]=='*') return true;
	else if(p.arr[0][1]=='*' && p.arr[1][1]=='*' && p.arr[2][1]=='*') return true;
	else if(p.arr[0][2]=='*' && p.arr[1][2]=='*' && p.arr[2][2]=='*') return true;
	else return false;
}

bool check_cross_for_win(matrix &p){
	if(p.arr[0][0]=='*' && p.arr[1][1]=='*' && p.arr[2][2]=='*') return true;
	else if(p.arr[0][2]=='*' && p.arr[1][1]=='*' && p.arr[2][0]=='*') return true;
	else return false;
}

bool check_for_win(matrix &p){
	if(check_row_for_win(p)) return true;
	else if(check_column_for_win(p)) return true;
	else if(check_cross_for_win(p)) return true;

	else return false;
}


bool check_row_for_lose(matrix &p){
	if(p.arr[0][0]=='0' && p.arr[0][1]=='0' && p.arr[0][2]=='0') return true;
	else if(p.arr[1][0]=='0' && p.arr[1][1]=='0' && p.arr[1][2]=='0') return true;
	else if(p.arr[2][0]=='0' && p.arr[2][1]=='0' && p.arr[2][2]=='0') return true;
	else return false;
}

bool check_column_for_lose(matrix &p){
	if(p.arr[0][0]=='0' && p.arr[1][0]=='0' && p.arr[2][0]=='0') return true;
	else if(p.arr[0][1]=='0' && p.arr[1][1]=='0' && p.arr[2][1]=='0') return true;
	else if(p.arr[0][2]=='0' && p.arr[1][2]=='0' && p.arr[2][2]=='0') return true;
	else return false;
}

bool check_cross_for_lose(matrix &p){
	if(p.arr[0][0]=='0' && p.arr[1][1]=='0' && p.arr[2][2]) return true;
	else if(p.arr[0][2]=='0' && p.arr[1][1]=='0' && p.arr[2][0]) return true;
	else return false;
}

bool check_for_lose(matrix &p){
	if(check_row_for_lose(p)) return true;
	else if(check_column_for_lose(p)) return true;
	else if(check_cross_for_lose(p)) return true;

	else return false;
}
bool check_for_tie(matrix &p){
	

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++) {if(p.arr[i][j]=='?') return false;}
	}

	return true;
}

int main(){
	matrix a;
	
	while(true){
		a.print_matrix();
		int row_number,column_number;
		cout<<"enter the row number and column number respectively "<<endl;
		cin>>row_number>>column_number;

		if((row_number<1 || row_number>3) || (column_number<1 || column_number>3)) {
			cout<<endl<<"!!!!!!!!invalid row or column number!!!!!!!!!!"<<endl;continue;
		}

		else {
			if(a.arr[row_number-1][column_number-1]=='*' || a.arr[row_number-1][column_number-1]=='0') {
				cout<<endl<<"NOT POSSIBLE ! Plz try again!!"<<endl;
				continue;
			}
			else a.upgrade_matrix(row_number,column_number);
		}

		if(check_win_condition(a)==true) put_winning_zero(a);
		else if(check_end_condition(a)==true) {
			position pos;
			pos=give_position(a);

			a.arr[pos.row][pos.column]='0';
		}

		else put_zero(a);

		if(check_for_win(a)) {a.print_matrix(); cout<<"congrats !!You Win !!!!"<<endl;break;}
		else if(check_for_lose(a)){a.print_matrix();cout<<"Sorry! GAME OVER!You lost"<<endl;break;}

		if(check_for_tie(a)==true) {a.print_matrix(); cout<<"Game Tied !!"<<endl;break;}

	}
	return 0;
}