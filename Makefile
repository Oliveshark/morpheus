all:
	@make -sC build/debug
.PHONY: all

clean:
	@make clean -sC build/debug
	@make clean -sC build/release
.PHONY: clean

test:
	@make test -sC build/debug
.PHONY: test

run: $(all)
	@./build/debug/morpheus
.PHONY: run

lint:
	@make lint -sC build/debug
.PHONY: lint
