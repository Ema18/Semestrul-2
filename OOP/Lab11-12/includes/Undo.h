#pragma once

#include "Movie.h"
#include "Repository.h"

class UndoAction
{
public:
	virtual void executeUndo() = 0;
	// virtual destructor!
	virtual ~UndoAction() {};
};

class UndoAdd : public UndoAction
{
private:
	Movie addedMovie;
	Repository& repo;	// we keep a reference to the repo to be able to undo
	
public:
	UndoAdd(Repository& _repo, const Movie& m) : repo{ _repo }, addedMovie{ m } {}

	void executeUndo() override
	{
		this->repo.removeMovie(addedMovie);
	}
};

class UndoRemove : public UndoAction
{
private:
	Movie deletedMovie;
	Repository& repo;

public:
	UndoRemove(Repository& _repo, const Movie& m) : repo{ _repo }, deletedMovie{ m } {}

	void executeUndo() override
	{
		this->repo.addMovie(deletedMovie);
	}
};