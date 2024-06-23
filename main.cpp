#include <iostream>

using namespace std;
struct Product
{
    string name,code;
    double price,tax_percentage;
};
struct Product_in_order
{
    string code;
    int quantity;
};
double calculate_tax_value(double price , double tax)
{
    return price * tax * (1.0/100);
}
int main()
{
    bool next_order =  true;
    int num_of_served_order=0;
    double total_money=0;
    int num_of_availble_products;
    cout <<"Please Enter Number of available products in the market : "<<endl;
    cin >> num_of_availble_products;
    Product arr[num_of_availble_products];
    for(int i=0;i<num_of_availble_products;i++)
    {
        cout <<"Please Enter product name , code , price , tax : "<<endl;
        cin >>arr[i].name>>arr[i].code>>arr[i].price>>arr[i].tax_percentage;
    }
while(next_order ==true)
{


    cout <<"Now we are ready to accept orders "<<endl;
    cout <<"Please Enter number of products in the order :  "<<endl;
    int num_of_product_in_order;
    cin >> num_of_product_in_order;
    Product_in_order arr_of_prod_in_order[num_of_product_in_order];
    for(int i=0;i<num_of_product_in_order;i++)
    {
        cout <<"Please Enter product code and quantity : "<<endl;
        cin >>arr_of_prod_in_order[i].code>>arr_of_prod_in_order[i].quantity;
    }
    cout <<"ProductName          price         tax           final price         quantity        total price   "<<endl;
    for(int i=0;i<num_of_product_in_order;i++)
    {
        for(int j=0;j<num_of_availble_products;j++)
        {
            if((arr_of_prod_in_order[i].code)==(arr[j].code))
            {
                int total = (arr[j].price+calculate_tax_value(arr[j].price,arr[j].tax_percentage))*arr_of_prod_in_order[i].quantity;
                total_money+=total;
                cout <<arr[j].name  <<"                     "<<arr[j].price<<"            "<<calculate_tax_value(arr[j].price,arr[j].tax_percentage)<<"          "<<(arr[j].price+calculate_tax_value(arr[j].price,arr[j].tax_percentage))<<"                 "<<arr_of_prod_in_order[i].quantity<<"                "<<total<<endl;
            }
        }
    }

    cout <<"---------------------- "<<endl;
    cout <<"Total Amount is : "<<total_money<<endl;
    cout <<"---------------------- "<<endl;
    cout << "Do you want to start a new order ? (1 or 0 )"<<endl;
    int choice ;
    cin >> choice;
    if(choice ==1)
        next_order=true;
    else
        next_order = false;
    num_of_served_order++;
}
cout <<"Number of served order is : "<<num_of_served_order<<endl;
cout <<"Total Amount of all orders is :  "<<total_money<<endl;
    return 0;
}
