package tree_sitter_hylo_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_hylo "github.com/tree-sitter/tree-sitter-hylo/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_hylo.Language())
	if language == nil {
		t.Errorf("Error loading Hylo grammar")
	}
}
