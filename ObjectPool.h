#pragma once
#include <vector>

template <class T>
class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();
	//�ǉ����鐔
	void SetPlus(const unsigned int addsize);
	//object�̎擾
	T* GetObject();
	//object�̎��
	void ReturnObject(T** object);
	//object��
	unsigned int GetSize();
	//����object���A�N�e�B�u���ǂ���
	bool Getactive(T* object);
	//�����[�X
	void Release();

private:
	std::vector<T*> m_objectlist;
	std::vector<bool> m_objectchlist;
};

template<class T>
inline ObjectPool<T>::ObjectPool()
{

}

template<class T>
inline ObjectPool<T>::~ObjectPool()
{
	Release();
}

template<class T>
inline void ObjectPool<T>::SetPlus(const unsigned int addsize)
{
	for (unsigned int i = 0; i < addsize; i++)
	{
		m_objectlist.push_back(new T);
		m_objectchlist.push_back(false);
	}
}

template<class T>
inline T* ObjectPool<T>::GetObject()
{
	for (unsigned int i = 0; i < m_objectchlist.size(); i++)
	{
		if (m_objectchlist.at(i) == false)
		{
			m_objectchlist.at(i) = true;
			return m_objectlist.at(i);
		}
	}
	//m_objectchlist->at(index) = true;

	return nullptr;
}

template<class T>
inline void ObjectPool<T>::ReturnObject(T** object)
{
	int index = 0;
	for (unsigned int i = 0; i < m_objectlist.size(); i++)
	{
		if (*object == m_objectlist.at(i))
		{
			*object = nullptr;
			m_objectchlist.at(i) = false;
			return;
		}
	}
	
}

template<class T>
inline unsigned int ObjectPool<T>::GetSize()
{
	return m_objectlist.size();
}

template<class T>
inline bool ObjectPool<T>::Getactive(T* object)
{
	for (unsigned int i = 0; i < m_objectlist.size(); i++)
	{
		if (object == m_objectlist.at(i))
		{
			return m_objectchlist.at(i);
		}
	}
	return false;
}

template<class T>
inline void ObjectPool<T>::Release()
{
	for (unsigned int i = 0; i < m_objectlist.size(); i++)
	{
		delete m_objectlist.at(i);
	}
	m_objectchlist.clear();
	m_objectlist.clear();

}
