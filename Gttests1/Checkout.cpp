#include "pch.h"
#include "Checkout.h"


Checkout::Checkout():total(0)
{
}


Checkout::~Checkout()
{
}
void Checkout::addItemPrice(std::string item, int price) {
	prices[item]=price;
	
}
void Checkout::addItem(std::string item) {
	//items[item]++;
	std::map<std::string, int>::iterator priceIter = prices.find(item);
	if (priceIter == prices.end()) {
		throw std::invalid_argument("Invalid imtem, No price");

	}
	items[item]++;
}
void Checkout::addDiscount(std::string item, int nbrOfItems, int discountPrice) {
	Discount discount;
	discount.nbrOfItems = nbrOfItems;
	discount.discountPrice = discountPrice;
	discounts[item] = discount;
}
int Checkout::calculateTotal() {
	total = 0;
	for (std::map<std::string, int>::iterator itemIter = items.begin(); itemIter != items.end(); itemIter++) {
		std::string item = itemIter->first;
		int itemCnt = itemIter->second;
		calculateItem(item, itemCnt);
		/*std::map<std::string, Discount>::iterator discountIter;
		discountIter = discounts.find(item);
		if (discountIter != discounts.end()) {
			Discount discount = discountIter->second;
			if (itemCnt >= discount.nbrOfItems) {
				int  nbrOfDiscounts = itemCnt / discount.nbrOfItems;
				total += nbrOfDiscounts * discount.discountPrice;
				int remainingItems = itemCnt % discount.nbrOfItems;
				total += remainingItems * prices[item];

			}
			else {
				total += itemCnt * prices[item];
			}
		}
		else {
			total += itemCnt * prices[item];
		}*/
	}
	return total;
}
void Checkout::calculateItem(std::string item, int itemCnt) {
	std::map<std::string, Discount>::iterator discountIter;
	discountIter = discounts.find(item);
	if (discountIter != discounts.end()) {
		Discount discount = discountIter->second;
		calculateDiscount(item, itemCnt, discount);
		/*if (itemCnt >= discount.nbrOfItems) {
			int  nbrOfDiscounts = itemCnt / discount.nbrOfItems;
			total += nbrOfDiscounts * discount.discountPrice;
			int remainingItems = itemCnt % discount.nbrOfItems;
			total += remainingItems * prices[item];

		}
		else {
			total += itemCnt * prices[item];
		}*/
	}
	else {
		total += itemCnt * prices[item];
	}
}
void Checkout:: calculateDiscount(std::string item, int itemCnt, Discount discount) {
	if (itemCnt >= discount.nbrOfItems) {
		int  nbrOfDiscounts = itemCnt / discount.nbrOfItems;
		total += nbrOfDiscounts * discount.discountPrice;
		int remainingItems = itemCnt % discount.nbrOfItems;
		total += remainingItems * prices[item];

	}
	else {
		total += itemCnt * prices[item];
	}
}