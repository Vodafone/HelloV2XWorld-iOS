//
//  PDFViewer.swift
//  HelloV2XWorld
//
//  Created by Mohamed Elabd on 12/01/2023.
//

import SwiftUI
import PDFKit

struct PDFKitView: UIViewRepresentable {
    @Binding var document: PDFDocument
    @Binding var enableAcceptButton: Bool

    func makeUIView(context: UIViewRepresentableContext<PDFKitView>) -> PDFView {
        let pdfView = PDFView()
        pdfView.document = document
        pdfView.autoScales = true
        pdfView.minScaleFactor = pdfView.contentScaleFactor
        pdfView.displaysPageBreaks = false
        pdfView.displayMode = .singlePageContinuous
        pdfView.backgroundColor = .clear

        NotificationCenter.default.addObserver(forName: .PDFViewPageChanged, object: nil, queue: nil) { _ in
            if let count = pdfView.document?.pageCount, let currentPage = pdfView.currentPage?.pageRef?.pageNumber {
                if count == currentPage {
                    self.enableAcceptButton = true
                }
            }
        }

        return pdfView
    }

    func updateUIView(_ view: PDFView, context: UIViewRepresentableContext<PDFKitView>) {
        view.document = document
    }
}
