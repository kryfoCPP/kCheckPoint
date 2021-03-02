#pragma once

#include <maya/MPxCommand.h>
#include <maya/MArgDatabase.h>
#include <maya/MSyntax.h>
#include <maya/MGlobal.h>
#include <maya/MSelectionList.h>
#include <maya/MItSelectionList.h>
#include <maya/MDagPath.h>
#include <maya/MFnSingleIndexedComponent.h>
#include <maya/MPoint.h>
#include <maya/MFloatPoint.h>
#include <maya/MPointArray.h>
#include <maya/MItMeshPolygon.h>
#include <maya/MItMeshVertex.h>
#include <maya/MString.h>
#include <maya/MStringArray.h>
#include <maya/MIntArray.h>
#include <maya/MSelectionMask.h>
#include <maya/MItDag.h>

class kSP :public MPxCommand {

public:
	kSP() {};
	virtual ~kSP() {};

	virtual MStatus doIt(const MArgList& args);
	virtual MStatus redoIt();
	bool visibility(MDagPath dag_path);
	virtual MStatus undoIt();

	virtual bool isUndoable()const { return true; };
	static void* creator() { return new kSP; };
	static MSyntax newSyntax();
	bool visibility() {};

private:
	MSelectionList cSelList;
	MPoint camPoint;
	MIntArray kResult;
	double nearDst;
	double mediumDst;
	double farDst;

	int nearNum;
	int mediumNum;
	int farNum;

	bool checkVisibility;

};

