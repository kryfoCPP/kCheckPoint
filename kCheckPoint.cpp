#include "kCheckPoint.h"

MStatus kSP::doIt(const MArgList& args) {
	MStatus status;

	MArgDatabase argData(syntax(), args);
	if (argData.isFlagSet("cc")) {
		argData.getFlagArgument("cc", 0, camPoint.x);
		argData.getFlagArgument("cc", 1, camPoint.y);
		argData.getFlagArgument("cc", 2, camPoint.z);
	}
	else {
		camPoint.x = 0;
		camPoint.y = 0;
		camPoint.z = 0;
	}
	
	if (argData.isFlagSet("n")) {
		status = argData.getFlagArgument("n", 0, nearDst);
		CHECK_MSTATUS_AND_RETURN_IT(status);
	}
	else {
		nearDst = 1;
	};
	if (argData.isFlagSet("m")) {
		status = argData.getFlagArgument("m", 0, mediumDst);
		CHECK_MSTATUS_AND_RETURN_IT(status);
	}
	else {
		mediumDst = 1;
	};
	
	if (argData.isFlagSet("f")) {
		status = argData.getFlagArgument("f", 0, farDst);
		CHECK_MSTATUS_AND_RETURN_IT(status);
	}
	else {
		farDst = 1;
	};
	
	if (argData.isFlagSet("cv")) {
		status = argData.getFlagArgument("cv", 0, checkVisibility);
		CHECK_MSTATUS_AND_RETURN_IT(status);
	}
	else {
		checkVisibility = false;
	};
	

	return redoIt();
	//return MS::kSuccess;

}

MStatus kSP::redoIt() {
	MStatus status;

	 nearNum = 0;
	 mediumNum = 0;
	 farNum = 0;

	 
	 for (MItDag allMesh(MItDag::kDepthFirst, MFn::kMesh); !allMesh.isDone(); allMesh.next()) {
		 MDagPath dag_path;
		 allMesh.getPath(dag_path);

		 if (visibility(dag_path)) {

			 for (MItMeshVertex kMesh(dag_path); !kMesh.isDone(); kMesh.next()) {
				 MPoint kMeshVert;

				 kMeshVert = kMesh.position(MSpace::kWorld);

				 float distance = std::sqrt(std::pow(kMeshVert.x - camPoint.x, 2)
					 + std::pow(kMeshVert.y - camPoint.y, 2)
					 + std::pow(kMeshVert.z - camPoint.z, 2));

				 if (distance <= nearDst) {
					 nearNum++;
				 }
				 if (distance <= mediumDst) {
					 mediumNum++;
				 }
				 if (distance <= farDst) {
					 farNum++;
				 }

			 }

		 }

	 }

	 kResult.clear();
	kResult.append(nearNum);
	kResult.append(mediumNum);
	kResult.append(farNum);

	setResult(kResult);
	return MS::kSuccess;
}

bool kSP::visibility(MDagPath dag_path) {
	bool kResult;
	if (checkVisibility) {
		kResult = dag_path.isVisible();
	}
	else {
		kResult = true;
	}
	return kResult;
}

MStatus kSP::undoIt() {
	MStatus status;

	return MS::kSuccess;
}

MSyntax kSP::newSyntax() {
	MSyntax syntax;
	syntax.addFlag("cc", "cameraCenter", MSyntax::kDouble, MSyntax::kDouble, MSyntax::kDouble);
	syntax.addFlag("n", "near", MSyntax::kDouble);
	syntax.addFlag("m", "medium", MSyntax::kDouble);
	syntax.addFlag("f", "farway", MSyntax::kDouble);
	syntax.addFlag("cv", "checkVisibili", MSyntax::kBoolean);
	
	
	return syntax;
}