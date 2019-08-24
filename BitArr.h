// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SIBAL_API BitArr
{
public:
	BitArr(const int32& number, const bool& val);
	BitArr() { __bitArr = nullptr; }
	~BitArr();
	//----------------------------------------------
	void CreateSetup(const int32& number , const bool& val);
	void empty();
	const bool& GetData(const int32& number);
	void SetData(const int32& number, const bool& val);

private:
	int8* __bitArr;
};

class BitArr2D {
public:
	BitArr2D(const int32& numberY,const int32& numberX, const bool& val);
	BitArr2D() { __bitArr2 = nullptr; }
	~BitArr2D();
	//----------------------------------------------
	void CreateSetup(const int32& numberY, const int32& numberX, const bool& val);
	void empty();
	const bool& GetData(const int32& numberY, const int32& numberX);
	void SetData(const int32& numberY, const int32& numberX, const bool& val);

private:
	BitArr* __bitArr2;
};

class BitArr3D {
public:
	BitArr3D(const int32& numberZ, 
		const int32& numberY, const int32& numberX, const bool& val);
	BitArr3D() { __bitArr3 = nullptr; }
	~BitArr3D();
	//----------------------------------------------
	void CreateSetup(const int32& numberZ,
		const int32& numberY, const int32& numberX, const bool& val);
	void empty();
	const bool& GetData(const int32& numberZ, const int32& numberY, const int32& numberX);
	void SetData(const int32& numberZ,
		const int32& numberY, const int32& numberX, const bool& val);

private:
	BitArr2D* __bitArr3;
};
