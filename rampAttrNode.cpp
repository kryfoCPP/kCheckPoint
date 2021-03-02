#include "rampAttrNode.h"

MTypeId kRampAttrNode::id(0x81027);
MObject kRampAttrNode::input1;
MObject kRampAttrNode::input2;
MObject kRampAttrNode::input3;

void kRampAttrNode::postConstructor()
{
    MPlug curvePlug(thisMObject(), kRampAttrNode::input3);
    MCurveAttribute curveAttr(curvePlug);
    MFloatArray pos;
    pos.append(0.0f);
    pos.append(0.25f);
    pos.append(0.5f);
    pos.append(1.0f);
    MFloatArray val;
    val.append(0.0f);
    val.append(0.25f);
    val.append(0.50f);
    val.append(1.0f);
    MStatus stat = curveAttr.setCurve(pos, val);
    if (!stat)
    {
        cout << "ERROR setting curve points!\n";
    }
}
MStatus kRampAttrNode::initialize()
{
    MStatus stat;
    MString curveRamp("curveRamp");
    MString cvr("cvr");
    MString colorRamp("colorRamp");
    MString clr("clr");
    MString curveAttrRamp("curveAttrRamp");
    MString car("car");
    input1 = MRampAttribute::createCurveRamp(curveRamp, cvr);
    input2 = MRampAttribute::createColorRamp(colorRamp, clr);
    input3 = MCurveAttribute::createCurveAttr(curveAttrRamp, car);
    stat = addAttribute(input1);
    if (!stat)
    {
        cout << "ERROR in adding curveRamp Attribute!\n";
    }
    stat = addAttribute(input2);
    if (!stat)
    {
        cout << "ERROR in adding colorRamp Attribute!\n";
    }
    stat = addAttribute(input3);
    if (!stat)
    {
        cout << "ERROR in adding curveAttrRamp Attribute!\n";
    }
    return stat;
}
MStatus kRampAttrNode::compute(const MPlug& plug, MDataBlock& dataBlock)
{
    return(MStatus::kSuccess);
}
MStatus kRampAttrNode::shouldSave(const MPlug& plug, bool& result)
{
    if (plug == input3 || plug.parent() == input3) {
        result = true; // required to ensure curve attribute saved correctly
        return MS::kSuccess;
    }
    return MPxNode::shouldSave(plug, result);
}

