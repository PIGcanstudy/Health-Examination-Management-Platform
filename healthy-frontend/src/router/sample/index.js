const routes = [
  {
    path: '/sample',
    name: 'Sample',
    redirect: { path: '/sample/file' },
    component: () => import('@/views/sample/SampleView.vue'),
    children: [
      {
        path: '/sample/file',
        component: () => import('@/views/sample/file/FileUpload.vue')
      },
      {
        path: '/sample/excel',
        component: () => import('@/views/sample/excel/Excel.vue')
      },
      {
        path: '/sample/print',
        component: () => import('@/views/sample/print/Print.vue')
      },
      {
        path: '/sample/editor',
        component: () => import('@/views/sample/editor/Editor.vue')
      },
      {
        path: '/sample/pdfobject',
        component: () => import('@/views/sample/pdfobject/PdfObject.vue')
      },
      {
        path: '/sample/basedatalist',
        component: () => import('@/views/sample/pdfobject/BaseDataList.vue')
      },
      {
        path: '/sample/basedatalisttest',
        component: () => import('@/views/sample/pdfobject/BaseDataListTest.vue')
      },
      {
        path: '/sample/checkitems',
        component: () => import('@/views/sample/pdfobject/CheckItems.vue')
      },
      {
        path: '/sample/search',
        component: () => import('@/views/sample/pdfobject/Search.vue')
      },
      {
        path: '/sample/medicalinfo',
        component: () => import('@/views/sample/medicalinfo/MedicalInfo.vue')
      },
      {
        path: '/sample/details',
        component: () => import('@/views/sample/details/Details.vue')
      },
      {
        path: '/sample/newbutton',
        component: () => import('@/views/sample/pdfobject/NewButton.vue')
      },
      {
        path: '/sample/navigation',
        component: () => import('@/views/sample/pdfobject/Navigation.vue')
      },
      {
        path: '/sample/peoplelist',
        component: () => import('@/views/sample/pdfobject/PeopleList.vue')
      }
    ]
  }
]

export default routes
