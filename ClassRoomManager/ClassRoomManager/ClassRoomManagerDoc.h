
// ClassRoomManagerDoc.h : CClassRoomManagerDoc ��Ľӿ�
//


#pragma once
#include "ClassRoomManagerSet.h"


class CClassRoomManagerDoc : public CDocument
{
protected: // �������л�����
	CClassRoomManagerDoc();
	DECLARE_DYNCREATE(CClassRoomManagerDoc)

// ����
public:
	CClassRoomManagerSet m_ClassRoomManagerSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CClassRoomManagerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
