import XCTest
import SwiftTreeSitter
import TreeSitterHylo

final class TreeSitterHyloTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_hylo())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Hylo grammar")
    }
}
