#pragma once
	
class Builder  
{
	public:
		virtual ~Builder() = default;
		virtual void Reset() = 0;
		virtual void FillEmptyField() = 0;
		virtual void CreateObstacles() = 0;
		virtual void CreateExits() = 0;
};