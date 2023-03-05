#include<iostream>
using namespace std;
struct kindOfBook
{
    string natureBook;
    string socialBook;
};
// định nghĩa book
struct Book
{
    string bookCode;
    string nameBook;
    string Author;
    kindOfBook kind;
    int Year;
    int Cost;
    int Amount;
};
// fucntion nhập thông tin sách
void inputBookInformation(Book* &book, int &size){
    // Allocate memory for the array of books
    book = new Book[size];

    for (int i = 0; i < size; i++)
    {
        cout<<"Book code:";
        getline(cin,book[i].bookCode);
        cout<<"Name book:";
        getline(cin,book[i].nameBook);
        cout<<"Author:";
        getline(cin,book[i].Author);

        // Corrected the do-while loop condition
        int temp;
        do
        {
            cout<<"kind of book (1-nature book and 2-social book):";
            cin>>temp;
            cin.ignore();
            switch (temp)
            {
            case 1:
                cout<<"Nature book"<<endl;
                cin.ignore();
                break;
            case 2:
                cout<<"Social book"<<endl; 
                cin.ignore();
                break; 
            default:
                break;
            }
        } while (temp!=1 && temp!=2); 
        cout<<"Year:";
        cin>>book[i].Year;
        cin.ignore();
        cout<<"Cost:";
        cin>>book[i].Cost;
        cin.ignore();
        cout<<"Amount want buy:";
        cin>>book[i].Amount;
        cin.ignore();
    }
}
//function xuất thông tin sách
void outputBookInformation(Book *book,int size){
    cout<<"----------------BOOK-----------------"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Book " << i+1 << ":" << endl;
        cout << "Book code: " << book[i].bookCode << endl;
        cout << "Name book: " << book[i].nameBook << endl;
        cout << "Author: " << book[i].Author << endl;
        cout << "Year: " << book[i].Year << endl;
        cout << "Cost: " << book[i].Cost << endl;
        cout << "Amount want buy: " << book[i].Amount << endl;
        cout << endl;
    }
}
void addBook(Book* &book, int &size){
    // Tạo một mảng tạm với size lớn hơn 1 đơn vị so với mảng ban đầu
    Book* tempBook = new Book[size + 1];

    // Sao chép các phần tử của mảng ban đầu vào mảng tạm
    for (int i = 0; i < size; i++) {
        tempBook[i] = book[i];
    }

    // Nhập thông tin cuốn sách mới
    cout<<"Book code:";
    getline(cin,tempBook[size].bookCode);
    cout<<"Name book:";
    getline(cin,tempBook[size].nameBook);
    cout<<"Author:";
    getline(cin,tempBook[size].Author);

    // Corrected the do-while loop condition
    int temp;
    do
    {
        cout<<"kind of book (1-nature book and 2-social book):";
        cin>>temp;
        cin.ignore();
        switch (temp)
        {
        case 1:
            cout<<"Nature book"<<endl;
            tempBook[size].kind.natureBook = "Nature book";
            cin.ignore();
            break;
        case 2:
            cout<<"Social book"<<endl; 
            tempBook[size].kind.socialBook = "Social book";
            cin.ignore();
            break; 
        default:
            break;
        }
    } while (temp!=1 && temp!=2); 
    cout<<"Year:";
    cin>>tempBook[size].Year;
    cin.ignore();
    cout<<"Cost:";
    cin>>tempBook[size].Cost;
    cin.ignore();
    cout<<"Amount want buy:";
    cin>>tempBook[size].Amount;
    cin.ignore();

    // Tăng size của mảng
    size++;
    
    // Xóa mảng ban đầu
    delete[] book;

    // Trỏ đến mảng mới
    book = tempBook;
}
void totalBook(Book* book, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += book[i].Amount * book[i].Cost;
    }
    cout << "Total:"<<total<<"$"<<endl;
}
// function sắp xếp giá
void Sort(Book *book, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (book[i].Cost>book[j].Cost)  
            {
                swap(book[i].Cost, book[j].Cost); 
            }   
        }
    }
}
// fuction find book
string findBook(Book* book, int size){
    if (size == 0) {
        return "Error: No books found";
    }
    string find;
    cout << "Enter the name of the book you want to find: ";
    getline(cin, find);
    for (int i = 0; i < size; i++) {
        if (book[i].nameBook == find) {
            cout<< "Book code: " << book[i].bookCode << endl;
            cout<< "Name book: " << book[i].nameBook << endl;
            cout<< "Author: " << book[i].Author << endl;
            cout<< "Kind of book: " << (book[i].kind.natureBook != "" ? book[i].kind.natureBook : book[i].kind.socialBook) << endl;
            cout<< "Year: " << book[i].Year << endl;
            cout<< "Cost: " << book[i].Cost << endl;
            cout<< "Amount want buy: " << book[i].Amount << endl;
        }
    }
    return "Error: Book not found";
}

// fuction xuất các quyển sách sản xuất trước năm 2000
int ouputBook2000(Book *book, int size){
    if (size==0)
    {
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (book->Year>2000)
        {
            cout<< "Book code: " << book[i].bookCode << endl;
            cout<< "Name book: " << book[i].nameBook << endl;
            cout<< "Author: " << book[i].Author << endl;
            cout<< "Kind of book: " << (book[i].kind.natureBook != "" ? book[i].kind.natureBook : book[i].kind.socialBook) << endl;
            cout<< "Year: " << book[i].Year << endl;
            cout<< "Cost: " << book[i].Cost << endl;
            cout<< "Amount want buy: " << book[i].Amount << endl;
        }
        
    }
    return -1;
}
// function đếm tất cả những cuốn sách có cost lớn hơn 50$
void outputBookOrMore50(Book *book, int size){
    int count=0;
    if (size==0)
    {
        cout<< 0;
    }else
    {
        for (int i = 0; i < size; i++)
        {
            if (book->Cost>=50)
            {
                cout<<book[i].nameBook<<endl;
                count++;
            }
        }
    }
    cout<<count;
}
//function xuất cuốn sách theo loại 
string outputKindOfBook(Book *book, int size){
    if (size==0)
    {
        return ;
    }
    string find;
    cout<<"find:";
    getline(cin,find);
    if (find==book->kind.natureBook)
    {
        for (int i = 0; i < size; i++)
        {
            cout<< "Book code: " << book[i].bookCode << endl;
            cout<< "Name book: " << book[i].nameBook << endl;
            cout<< "Author: " << book[i].Author << endl;
            cout<< "Kind of book: "<<book[i].kind.natureBook<<endl;
            cout<< "Cost: " << book[i].Cost << endl;
        }   
    }else if (find==book->kind.socialBook)
    {
        for (int i = 0; i < size;i++)
        {
            cout<< "Book code: " << book[i].bookCode << endl;
            cout<< "Name book: " << book[i].nameBook << endl;
            cout<< "Author: " << book[i].Author << endl;
            cout<< "Kind of book: "<<book[i].kind.socialBook<<endl;
            cout<< "Cost: " << book[i].Cost << endl;
        }
    }
    return "Find Not!";
}
void MENU(){
    cout<<endl<<"+-----------------------------+"<<endl;
    cout<<"|=============MENU============|"<<endl;
    cout<<"+-----------------------------+"<<endl;
    cout<<"| INPUT BOOK | ENTER 1 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"| OUTPUT BOOK| ENTER 2 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"| ADD BOOK   | ENTER 3 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"| TOTAL BOOK | ENTER 4 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"| SORT BOOK  | ENTER 5 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"| FIND BOOK  | ENTER 6 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"| OUTPUT >50 | ENTER 7 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"| OUTPUT KIND| ENTER 8 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
    cout<<"|    EXIT    | ENTER 0 PLEASE |"<<endl;
    cout<<"+------------+----------------+"<<endl;
        
}
int main(){
    Book *book;
    int point;
    int size;
    do
    {
        MENU();
        cout<<"point:";
        cin>>point;
        cin.ignore();
        switch (point)
        {
        case 1:
            cout<<"size:";
            cin>>size;
            cin.ignore();
            inputBookInformation(book,size);
            break;
        case 2:
            outputBookInformation(book,size);
            break;
        case 3:
            addBook(book,size);
            break;
        case 4:
            totalBook(book,size);
            break;
        case 5:
            Sort(book,size);
            break;
        case 6:
            cout<<findBook(book,size);
            break;
        case 7:
            outputBookOrMore50(book,size);
            break;
        case 8:
            outputKindOfBook(book,size);
            break;
        default:
            break;
        }
    } while (point!=0);

    delete[] book;
    return 0;
}
