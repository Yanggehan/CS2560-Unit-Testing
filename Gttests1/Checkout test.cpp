#include "pch.h"
#include <iostream>
#include<gtest/gtest.h>
#include"Checkout.h"
using namespace std;
class CheckoutTests :public ::testing::Test {
public:

protected:
	Checkout checkOut;
};
/*TEST(CheckoutTests, CanInstantiateCheckout) {
	Checkout co;
}*/
/*TEST_F(CheckoutTests, CanAddItemPrice) {
	
	checkOut.addItemPrice("a", 1);
}
TEST_F(CheckoutTests, CanAddItem) {
	
	checkOut.addItem("a");
}*/
TEST_F(CheckoutTests, CancalculateTotal) {

	checkOut.addItemPrice("a", 1);
	checkOut.addItem("a");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(1, total);
}
TEST_F(CheckoutTests, CanGetTotalForMultipleItems) {

	checkOut.addItemPrice("a", 1);
	checkOut.addItemPrice("b", 2);
	checkOut.addItem("a");
	checkOut.addItem("b");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(3, total);
}
TEST_F(CheckoutTests, CanAddDiscount) {
	checkOut.addDiscount("a", 3, 2);
}
TEST_F(CheckoutTests, CancalculateTotalWithDiscount) {
	checkOut.addItemPrice("a", 1);
	checkOut.addDiscount("a", 3, 2);
	checkOut.addItem("a");
	checkOut.addItem("a");
	checkOut.addItem("a");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(2, total);

}
TEST_F(CheckoutTests, itemWithNoPriceThrowsException) {
	ASSERT_THROW(checkOut.addItem("a"), std::invalid_argument);
}