#include "Path4.h"

#include "Animation.h"

void Path4::PushBack(fPoint speed, uint frames, Animation* animation)
{
	steps[totalSteps].animation = animation;
	steps[totalSteps].framesDuration = frames;
	steps[totalSteps].speed = speed;
	totalSteps++;
}

void Path4::Update()
{
	currentStepFrame += 1;

	if (currentStepFrame > steps[currentStep].framesDuration)
	{
		if (currentStep < totalSteps - 1) // If it is not the last step, advance
		{
			currentStep++;
		}
		else if (loop) // Otherwise, if the path loops, go back to the beginning
		{
			currentStep = 0;
		}
		currentStepFrame = 0;
	}

	relativePosition += steps[currentStep].speed;
}

fPoint Path4::GetRelativePosition() const
{
	return fPoint((int)relativePosition.x, (int)relativePosition.y);
}

Animation* Path4::GetCurrentAnimation()
{
	return steps[currentStep].animation;
}

void Path4::Reset()
{
	currentStepFrame = 0;
	currentStep = 0;
}