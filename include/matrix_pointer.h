#include "tvector.h"

// ����������������� �������
template <class ValType>
class TPointerMatrix {
private:
	TVector<ValType> **pMatrix;
	int Size;
public:
	TPointerMatrix(int s = 10);
	TPointerMatrix(const TPointerMatrix &mt);                    // �����������
	TPointerMatrix(const TVector<TVector<ValType> > &mt); // �������������� ����
	virtual ~TPointerMatrix();

	int GetSize() const { return Size; }
	TVector<ValType>& operator[](int pos) const;             // ������
	bool operator==(const TPointerMatrix &mt) const;      // ���������
	bool operator!=(const TPointerMatrix &mt) const;      // ���������
	TPointerMatrix& operator= (const TPointerMatrix &mt);        // ������������
	TPointerMatrix  operator+ (const TPointerMatrix &mt);        // ��������
	TPointerMatrix  operator- (const TPointerMatrix &mt);        // ���������
	TPointerMatrix  operator* (const TPointerMatrix &mt);		 // ���������

	// ���� / �����
	friend istream& operator>>(istream &in, TPointerMatrix &mt) {
		in >> mt.Size;
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<(ostream &out, const TPointerMatrix &mt) {
		out << mt.Size << endl;
		for (int i = 0; i < mt.Size; i++)
			out << *(mt.pMatrix[i]) << endl;
		return out;
	}
};

template <class ValType>
TPointerMatrix<ValType>::TPointerMatrix(int s){
	if (s<0) {
		throw invalid_argument("s<0 � Matrix_pointer");
	}
	if (s>MAX_MATRIX_SIZE) {
		throw invalid_argument("MAX_MATRIX_SIZE<s � Matrix_pointer");
	}
	Size = s;
	pMatrix = new TVector<ValType>*[s];
	for (int i = 0; i<s; i++)
		pMatrix[i] = new TVector<ValType>(s-i,i);
} /*-------------------------------------------------------------------------*/

template <class ValType>
TPointerMatrix<ValType>::~TPointerMatrix()
{
	for (int i = 0; i < Size; i++)
	{
		delete (pMatrix[i]);
	}
	delete []pMatrix;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ����������� �����������
TPointerMatrix<ValType>::TPointerMatrix(const TPointerMatrix<ValType> &mt){
	Size = mt.GetSize();
	pMatrix = new  TVector<ValType>* [mt.GetSize()];
	for (int i = 0; i<Size; i++)
		pMatrix[i] = new TVector<ValType>(Size - i, i);

	for (int i = 0; i < mt.GetSize();i++)
	{
		*pMatrix[i] = *(mt.pMatrix[i]);
	}
}

template <class ValType> // ������
TVector<ValType>& TPointerMatrix<ValType>::operator[](int pos) const {
	if (pos<0) {
		throw invalid_argument("[] pos<0");
	}if (pos>Size) {
		throw invalid_argument("[] pos>Size");
	}
	return *(pMatrix[pos]);
} /*-------------------------------------------------------------------------*/

//template <class ValType> // ����������� �������������� ����
//TPointerMatrix<ValType>::TPointerMatrix(const TVector<TVector<ValType> > &mt) :
//TVector<TVector<ValType> >(mt) {}

template <class ValType> // ���������
bool TPointerMatrix<ValType>::operator==(const TPointerMatrix<ValType> &mt) const {
	if (this == &mt) {
		return true;
	}

	if (Size != mt.GetSize()) {
		return false;
	}

	for (int i = 0; i < Size; i++) {
		if (*pMatrix[i] != *(mt.pMatrix[i]))
			return false;
	}

	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������� !=
bool TPointerMatrix<ValType>::operator!=(const TPointerMatrix<ValType> &mt) const {
	return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ������������
TPointerMatrix<ValType>& TPointerMatrix<ValType>::operator=(const TPointerMatrix<ValType> &mt) {
	if (this != &mt) {
		if (Size!=mt.GetSize())
		{
			for (int i = 0; i < Size; i++) {
				delete pMatrix[i];
			}
			delete []pMatrix;

			Size = mt.Size;
			pMatrix = new  TVector<ValType>*[mt.GetSize()];
			for (int i = 0; i<Size; i++)
				pMatrix[i] = new TVector<ValType>(Size - i, i);
		}
		
		for (int i = 0; i < mt.GetSize(); i++) {
			*pMatrix[i] = *(mt.pMatrix[i]);
		}
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TPointerMatrix<ValType> TPointerMatrix<ValType>::operator+(const TPointerMatrix<ValType> &mt) {
	if (Size != mt.GetSize()) {
		throw invalid_argument("������� ������� ������� +");
	}
	TPointerMatrix<ValType> result(Size);
	for (int i = 0; i < Size; i++) {
		result[i] = (*this)[i] + mt[i];
	}
	return result;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TPointerMatrix<ValType> TPointerMatrix<ValType>::operator-(const TPointerMatrix<ValType> &mt) {
	if (Size != mt.GetSize()) {
		throw invalid_argument("������� ������� ������� -");
	}
	TPointerMatrix<ValType> result(Size);
	for (int i = 0; i < Size; i++) {
		result[i] = (*this)[i] - mt[i];
	}
	return result;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TPointerMatrix<ValType> TPointerMatrix<ValType>::operator* (const TPointerMatrix<ValType> &mt) {
	if (Size != mt.GetSize()) {
		throw invalid_argument("������� ������� ������� -");
	}
	TPointerMatrix<ValType> result(Size);
	for (int i = 0; i < Size; i++)
		for (int j = i; j < Size; j++)
			for (int k = 0; k <= j; k++)
				result[i][j] = result[i][j] + ((*this)[i][k])*(mt[k][j]);
	return result;
} /*-------------------------------------------------------------------------*/