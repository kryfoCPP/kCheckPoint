#pragma once

#include <maya/MIOStream.h>
#include <maya/MPxNode.h> 
#include <maya/MFnPlugin.h>
#include <maya/MString.h> 
#include <maya/MTypeId.h> 
#include <maya/MPlug.h>
#include <maya/MRampAttribute.h>
#include <maya/MCurveAttribute.h>
class kRampAttrNode : public MPxNode
{
public:
    kRampAttrNode() {};
    ~kRampAttrNode() {};

    static  MStatus initialize();
    MStatus compute(const MPlug& plug, MDataBlock& dataBlock) override;
    static void* creator() { return new kRampAttrNode; };
    
    void    postConstructor() override;

    MStatus shouldSave(const MPlug&, bool&) override;
    static MObject input1;
    static MObject input2;
    static MObject input3;
    static MTypeId  id;

private:

    
};
