// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template <class T>
class MYSLATE_API MySlateSingleton
{
public:
	static TSharedPtr<T> Get();
private:
	static void Initialze();

	static TSharedRef<T> Create();

private:

	static TSharedPtr<T> TInstance;
};

template<class T>
TSharedPtr<T> MySlateSingleton<T>::TInstance = NULL;


template <class T>
TSharedPtr<T> MySlateSingleton<T>::Get()
{
	Initialze();
	return TInstance;
}

template <class T>
void MySlateSingleton<T>::Initialze()
{

	if (!TInstance.IsValid()) {
		TInstance = Create();
	}
}

template <class T>
TSharedRef<T> MySlateSingleton<T>::Create()
{
	TSharedRef<T> TRef = MakeShareable(new T());
	return TRef;
}