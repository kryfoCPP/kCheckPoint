#include <maya/MFnPlugin.h>
#include "rampAttrNode.h"

/*
MStatus initializePlugin(MObject obj)
{
	MStatus   status;
	MFnPlugin plugin(obj, "dengtao", "2020", "Any");


	status = plugin.registerCommand("kPoint", kSP::creator,kSP::newSyntax);
	if (status) {
		MGlobal::displayInfo("register kPoint success!!");
	}
	else
	{
		MGlobal::displayInfo("Failed to register kPoint!!");
	}

	status = plugin.registerNode("rampAttrNode", kRampAttrNode::id,
		kRampAttrNode::creator, kRampAttrNode::initialize);
	if (!status)
	{
		status.perror("registerNode");
		return status;
	}

	return status;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus   status;
	MFnPlugin plugin(obj); 

	status = plugin.deregisterCommand("kPoint");
	if (status) {
		MGlobal::displayInfo("unRegister kPoint success!!");
	}
	else
	{
		MGlobal::displayInfo("Failed to unRegister kPoint!!");
	}

	status = plugin.deregisterNode(kRampAttrNode::id);
	if (!status)
	{
		status.perror("deregisterNode");
		return status;
	}

	return status;
}
*/

MStatus initializePlugin(MObject obj)
{
	MStatus   status;
	MFnPlugin plugin(obj, "dengtao", "2020", "Any");


	status = plugin.registerNode("rampAttrNode", kRampAttrNode::id,
		kRampAttrNode::creator, kRampAttrNode::initialize);
	if (!status)
	{
		status.perror("registerNode");
		return status;
	}

	return status;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus   status;
	MFnPlugin plugin(obj);


	status = plugin.deregisterNode(kRampAttrNode::id);
	if (!status)
	{
		status.perror("deregisterNode");
		return status;
	}

	return status;
}