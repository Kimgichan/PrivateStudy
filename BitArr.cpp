// Fill out your copyright notice in the Description page of Project Settings.


#include "BitArr.h"

//-----------------------------------------------------------------
//BitArr
BitArr::BitArr(const int32& number, const bool& val)
{
	__bitArr = new int8[number / 8 + 1];
	if (val)
		memset(__bitArr, !0, number / 8 + 1);
	else
		memset(__bitArr, 0, number / 8 + 1);
}

BitArr::~BitArr()
{
	if (__bitArr != nullptr) {
		//에러 발생시키는 코드
	}
}

void BitArr::CreateSetup(const int32& number, const bool& val)
{
	if (__bitArr != nullptr) {
		;//에러 발생 코드
	}
	__bitArr = new int8[number / 8 + 1];
	if (val)
		memset(__bitArr, !0, number / 8 + 1);
	else
		memset(__bitArr, 0, number / 8 + 1);
}

void BitArr::empty()
{
	if (__bitArr == nullptr) return;
	delete[] __bitArr;
	__bitArr = nullptr;
}

const bool& BitArr::GetData(const int32 & number)
{
	return __bitArr[number / 8] & 1 << (number % 8);
}

void BitArr::SetData(const int32 & number, const bool & val)
{
	if (val) {
		__bitArr[number / 8] |= 1 << (number % 8);
	}
	else {
		__bitArr[number / 8] &= !(0 | (1 << (number % 8)));
	}
}





//-----------------------------------------------------------------
//BitArr2D

BitArr2D::BitArr2D(const int32 & numberY, const int32 & numberX, const bool & val)
{
	__bitArr2 = new BitArr[numberY];
	for (int32 y = 0; y < numberY; y++) {
		__bitArr2[y].CreateSetup(numberX, val);
	}
}

BitArr2D::~BitArr2D()
{
	if (__bitArr2 != nullptr) {
		//에러 발생시키는 코드
	}
}

void BitArr2D::CreateSetup(const int32& numberY, const int32& numberX, const bool& val)
{
	if (__bitArr2 != nullptr) {
		//에러 발생시키는 코드
	}
	__bitArr2 = new BitArr[numberY];
	for (int32 y = 0; y < numberY; y++) {
		__bitArr2[y].CreateSetup(numberX, val);
	}
}

void BitArr2D::empty()
{
	if (__bitArr2 == nullptr) return;
	delete[] __bitArr2;
	__bitArr2 = nullptr;
}

const bool & BitArr2D::GetData(const int32 & numberY, const int32 & numberX)
{
	return __bitArr2[numberY].GetData(numberX);
}

void BitArr2D::SetData(const int32 & numberY, const int32 & numberX, const bool & val)
{
	__bitArr2[numberY].SetData(numberX, val);
}





//-----------------------------------------------------------------
//BitArr3D

BitArr3D::BitArr3D(const int32 & numberZ, 
	const int32 & numberY, const int32 & numberX, const bool & val)
{
	__bitArr3 = new BitArr2D[numberZ];
	for (int32 z = 0; z < numberZ; z++) {
		__bitArr3[z].CreateSetup(numberY, numberX, val);
	}
}

BitArr3D::~BitArr3D()
{
	if (__bitArr3 != nullptr) {
		//에러 발생시키는 코드
	}
}

void BitArr3D::CreateSetup(const int32 & numberZ, 
	const int32 & numberY, const int32 & numberX, const bool & val)
{
	if (__bitArr3 != nullptr) {
		//에러 발생시키는 코드
	}
	__bitArr3 = new BitArr2D[numberZ];
	for (int32 z = 0; z < numberZ; z++) {
		__bitArr3[z].CreateSetup(numberY, numberX, val);
	}
}

void BitArr3D::empty()
{
	if (__bitArr3 == nullptr) return;
	delete[] __bitArr3;
	__bitArr3 = nullptr;
}

const bool & BitArr3D::GetData(const int32 & numberZ, 
	const int32 & numberY, const int32 & numberX)
{
	return __bitArr3[numberZ].GetData(numberY, numberX);
}

void BitArr3D::SetData(const int32 & numberZ, const int32 & numberY, const int32 & numberX, const bool & val)
{
	__bitArr3[numberZ].SetData(numberY, numberX, val);
}
