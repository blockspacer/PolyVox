namespace PolyVox
{
	template <typename VoxelType>
	Vector3DFloat computeCentralDifferenceGradient(const VolumeIterator<VoxelType>& volIter)
	{
		//FIXME - should this test be here?
		if((volIter.getPosX() < 1) || (volIter.getPosX() > POLYVOX_VOLUME_SIDE_LENGTH-2) ||
			(volIter.getPosY() < 1) || (volIter.getPosY() > POLYVOX_VOLUME_SIDE_LENGTH-2) ||
			(volIter.getPosZ() < 1) || (volIter.getPosZ() > POLYVOX_VOLUME_SIDE_LENGTH-2))
		{
			//LogManager::getSingleton().logMessage("Out of range");
			return Vector3DFloat(0.0,0.0,0.0);
		}

		//FIXME - bitwise way of doing this?
		VoxelType voxel1nx = volIter.peekVoxel1nx0py0pz() > 0 ? 1: 0;
		VoxelType voxel1px = volIter.peekVoxel1px0py0pz() > 0 ? 1: 0;

		VoxelType voxel1ny = volIter.peekVoxel0px1ny0pz() > 0 ? 1: 0;
		VoxelType voxel1py = volIter.peekVoxel0px1py0pz() > 0 ? 1: 0;

		VoxelType voxel1nz = volIter.peekVoxel0px0py1nz() > 0 ? 1: 0;
		VoxelType voxel1pz = volIter.peekVoxel0px0py1pz() > 0 ? 1: 0;

		return Vector3DFloat(int(voxel1px) - int(voxel1nx),int(voxel1py) - int(voxel1ny),int(voxel1pz) - int(voxel1nz));
	}

	template <typename VoxelType>
	Vector3DFloat computeSobelGradient(const VolumeIterator<VoxelType>& volIter)
	{
		//FIXME - should this test be here?
		if((volIter.getPosX() < 1) || (volIter.getPosX() > POLYVOX_VOLUME_SIDE_LENGTH-2) ||
			(volIter.getPosY() < 1) || (volIter.getPosY() > POLYVOX_VOLUME_SIDE_LENGTH-2) ||
			(volIter.getPosZ() < 1) || (volIter.getPosZ() > POLYVOX_VOLUME_SIDE_LENGTH-2))
		{
			//LogManager::getSingleton().logMessage("Out of range");
			return Vector3DFloat(0.0,0.0,0.0);
		}

		static const int weights[3][3][3] = {  {  {2,3,2}, {3,6,3}, {2,3,2}  },  {
			{3,6,3},  {6,0,6},  {3,6,3} },  { {2,3,2},  {3,6,3},  {2,3,2} } };

			const VoxelType pVoxel1nx1ny1nz = volIter.peekVoxel1nx1ny1nz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx1ny0pz = volIter.peekVoxel1nx1ny0pz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx1ny1pz = volIter.peekVoxel1nx1ny1pz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx0py1nz = volIter.peekVoxel1nx0py1nz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx0py0pz = volIter.peekVoxel1nx0py0pz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx0py1pz = volIter.peekVoxel1nx0py1pz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx1py1nz = volIter.peekVoxel1nx1py1nz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx1py0pz = volIter.peekVoxel1nx1py0pz() > 0 ? 1: 0;
			const VoxelType pVoxel1nx1py1pz = volIter.peekVoxel1nx1py1pz() > 0 ? 1: 0;

			const VoxelType pVoxel0px1ny1nz = volIter.peekVoxel0px1ny1nz() > 0 ? 1: 0;
			const VoxelType pVoxel0px1ny0pz = volIter.peekVoxel0px1ny0pz() > 0 ? 1: 0;
			const VoxelType pVoxel0px1ny1pz = volIter.peekVoxel0px1ny1pz() > 0 ? 1: 0;
			const VoxelType pVoxel0px0py1nz = volIter.peekVoxel0px0py1nz() > 0 ? 1: 0;
			//const VoxelType pVoxel0px0py0pz = volIter.peekVoxel0px0py0pz() > 0 ? 1: 0;
			const VoxelType pVoxel0px0py1pz = volIter.peekVoxel0px0py1pz() > 0 ? 1: 0;
			const VoxelType pVoxel0px1py1nz = volIter.peekVoxel0px1py1nz() > 0 ? 1: 0;
			const VoxelType pVoxel0px1py0pz = volIter.peekVoxel0px1py0pz() > 0 ? 1: 0;
			const VoxelType pVoxel0px1py1pz = volIter.peekVoxel0px1py1pz() > 0 ? 1: 0;

			const VoxelType pVoxel1px1ny1nz = volIter.peekVoxel1px1ny1nz() > 0 ? 1: 0;
			const VoxelType pVoxel1px1ny0pz = volIter.peekVoxel1px1ny0pz() > 0 ? 1: 0;
			const VoxelType pVoxel1px1ny1pz = volIter.peekVoxel1px1ny1pz() > 0 ? 1: 0;
			const VoxelType pVoxel1px0py1nz = volIter.peekVoxel1px0py1nz() > 0 ? 1: 0;
			const VoxelType pVoxel1px0py0pz = volIter.peekVoxel1px0py0pz() > 0 ? 1: 0;
			const VoxelType pVoxel1px0py1pz = volIter.peekVoxel1px0py1pz() > 0 ? 1: 0;
			const VoxelType pVoxel1px1py1nz = volIter.peekVoxel1px1py1nz() > 0 ? 1: 0;
			const VoxelType pVoxel1px1py0pz = volIter.peekVoxel1px1py0pz() > 0 ? 1: 0;
			const VoxelType pVoxel1px1py1pz = volIter.peekVoxel1px1py1pz() > 0 ? 1: 0;



			const int xGrad(- weights[0][0][0] * ( pVoxel1nx1ny1nz) -
				weights[1][0][0] * ( pVoxel1nx1ny0pz) - weights[2][0][0] *
				( pVoxel1nx1ny1pz) - weights[0][1][0] * ( pVoxel1nx0py1nz) -
				weights[1][1][0] * ( pVoxel1nx0py0pz) - weights[2][1][0] *
				( pVoxel1nx0py1pz) - weights[0][2][0] * ( pVoxel1nx1py1nz) -
				weights[1][2][0] * ( pVoxel1nx1py0pz) - weights[2][2][0] *
				( pVoxel1nx1py1pz) + weights[0][0][2] * ( pVoxel1px1ny1nz) +
				weights[1][0][2] * ( pVoxel1px1ny0pz) + weights[2][0][2] *
				( pVoxel1px1ny1pz) + weights[0][1][2] * ( pVoxel1px0py1nz) +
				weights[1][1][2] * ( pVoxel1px0py0pz) + weights[2][1][2] *
				( pVoxel1px0py1pz) + weights[0][2][2] * ( pVoxel1px1py1nz) +
				weights[1][2][2] * ( pVoxel1px1py0pz) + weights[2][2][2] *
				( pVoxel1px1py1pz));

			const int yGrad(- weights[0][0][0] * ( pVoxel1nx1ny1nz) -
				weights[1][0][0] * ( pVoxel1nx1ny0pz) - weights[2][0][0] *
				( pVoxel1nx1ny1pz) + weights[0][2][0] * ( pVoxel1nx1py1nz) +
				weights[1][2][0] * ( pVoxel1nx1py0pz) + weights[2][2][0] *
				( pVoxel1nx1py1pz) - weights[0][0][1] * ( pVoxel0px1ny1nz) -
				weights[1][0][1] * ( pVoxel0px1ny0pz) - weights[2][0][1] *
				( pVoxel0px1ny1pz) + weights[0][2][1] * ( pVoxel0px1py1nz) +
				weights[1][2][1] * ( pVoxel0px1py0pz) + weights[2][2][1] *
				( pVoxel0px1py1pz) - weights[0][0][2] * ( pVoxel1px1ny1nz) -
				weights[1][0][2] * ( pVoxel1px1ny0pz) - weights[2][0][2] *
				( pVoxel1px1ny1pz) + weights[0][2][2] * ( pVoxel1px1py1nz) +
				weights[1][2][2] * ( pVoxel1px1py0pz) + weights[2][2][2] *
				( pVoxel1px1py1pz));

			const int zGrad(- weights[0][0][0] * ( pVoxel1nx1ny1nz) +
				weights[2][0][0] * ( pVoxel1nx1ny1pz) - weights[0][1][0] *
				( pVoxel1nx0py1nz) + weights[2][1][0] * ( pVoxel1nx0py1pz) -
				weights[0][2][0] * ( pVoxel1nx1py1nz) + weights[2][2][0] *
				( pVoxel1nx1py1pz) - weights[0][0][1] * ( pVoxel0px1ny1nz) +
				weights[2][0][1] * ( pVoxel0px1ny1pz) - weights[0][1][1] *
				( pVoxel0px0py1nz) + weights[2][1][1] * ( pVoxel0px0py1pz) -
				weights[0][2][1] * ( pVoxel0px1py1nz) + weights[2][2][1] *
				( pVoxel0px1py1pz) - weights[0][0][2] * ( pVoxel1px1ny1nz) +
				weights[2][0][2] * ( pVoxel1px1ny1pz) - weights[0][1][2] *
				( pVoxel1px0py1nz) + weights[2][1][2] * ( pVoxel1px0py1pz) -
				weights[0][2][2] * ( pVoxel1px1py1nz) + weights[2][2][2] *
				( pVoxel1px1py1pz));

			return Vector3DFloat(xGrad,yGrad,zGrad);
	}
}