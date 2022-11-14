#include "Game.h"
#include <algorithm>

namespace lab9
{
	bool compare(IceCube* a, IceCube* b)
	{
		return a->GetLiveCount() > b->GetLiveCount();
	}

	Game::Game(unsigned int seed, unsigned int poolSize)
		: mRandom(seed)
		, mObjectPool(poolSize)
	{
	}

	Game::~Game()
	{
		//for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end(); ++it)
		//{
		//	delete (*it);
		//}

		//mActiveGameObjects.clear();
	}

	void Game::Spawn()
	{
		//IceCube* iceCube = new IceCube();
		//iceCube->Initialize(mRandom.GetNext() % MAX_FRAME_COUNT_TO_LIVE + 1);
		//mActiveGameObjects.push_back(iceCube);

		IceCube* iceCube = mObjectPool.Get();
		iceCube->Initialize(mRandom.GetNext() % MAX_FRAME_COUNT_TO_LIVE + 1);

		mActiveGameObjects.push_back(iceCube);
		std::sort(mActiveGameObjects.begin(), mActiveGameObjects.end(), compare);
	}

	void Game::Update()
	{
		//for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		//{
		//	IceCube* iceCube = *it;
		//	iceCube->Animate();

		//	if (!iceCube->IsActive())
		//	{
		//		it = mActiveGameObjects.erase(it);
		//		delete iceCube;
		//		continue;
		//	}

		//	++it;
		//}


		for (auto it = mActiveGameObjects.rbegin(); it != mActiveGameObjects.rend();)
		{
			IceCube* iceCube = *it;
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				mObjectPool.Return(*it);
				mActiveGameObjects.pop_back();
				it = mActiveGameObjects.rbegin();
				continue;
			}

			++it;
		}
	}

	const std::vector<IceCube*>& Game::GetActiveGameObjects()
	{
		return mActiveGameObjects;
	}

	ObjectPool<IceCube>& Game::GetObjectPool()
	{
		return mObjectPool;
	}


}